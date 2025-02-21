#include "FindUpDate.h"

int main(int argc, char *argv[])
{
    // 错误判定
    if (argc != 2)
    {
        return -1;
    }

    // 获取输入路径
    std::string inputPath = argv[1];

    // 打印输入文件路径
    std::cout << "Input path: " << inputPath.c_str() << std::endl;

    // 实例化修改文件名称
    FindUpDate f1(inputPath);

    // 批量修改文件名称
    f1.ChangeFileName();

    return 0;
}