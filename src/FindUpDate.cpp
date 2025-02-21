#include "FindUpDate.h"

// 构造函数
FindUpDate::FindUpDate(std::string path)
{
    this->m_Path = path;
}

// 析构函数
FindUpDate::~FindUpDate()
{
}

// 修改路径下文件名称
void FindUpDate::ChangeFileName()
{
    // 输入路径有效性判定
    DIR *dir = opendir(this->m_Path.c_str());
    if (dir == nullptr)
    {
        std::cout << "Can not open path: " << this->m_Path.c_str() << std::endl;
        return;
    }

    // 修改文件序号
    int newFileIndex = 1;

    // 逐个检查文件夹内文件
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr)
    {

        // 获取文件名称
        std::string filename = entry->d_name;

        // 检查文件是否为 .stp文件
        if (filename.length() > 4 && filename.substr(filename.length() - 4) == ".stp")
        {

            // 旧文件绝对路径
            std::string oldPath = this->m_Path + "/" + filename;

            // 新文件名与绝对路径
            std::string newFilename;
            std::string newPath;

            // 新文件名+ -01 -02 ... 逐次排列
            if (newFileIndex < 10)
            {
                newFilename = filename.substr(0, filename.length() - 4) + "-0" + std::to_string(newFileIndex) + ".stp";
            }
            else
            {
                newFilename = filename.substr(0, filename.length() - 4) + "-" + std::to_string(newFileIndex) + ".stp";
            }

            newPath = this->m_Path + "/" + newFilename;

            // 修改文件名
            if (rename(oldPath.c_str(), newPath.c_str()) != 0)
            {
                std::cout << "Can not rename file: " << oldPath << std::endl;
            }
            else
            {
                std::cout << "Rename file[" << newFileIndex << "]: " << oldPath << " -> " << newPath << std::endl;

                // 文件序号递增
                newFileIndex++;
            }
        }
    }

    // 关闭路径
    closedir(dir);
}
