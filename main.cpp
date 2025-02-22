#include "FindUpDate.h"

int main(int argc, char *argv[])
{
    while (true)
    {
        std::string inputPath;
        std::cout << "Please input path: " << std::endl;
        std::cin >> inputPath;
        std::cout << "You Input Path: " << inputPath << std::endl;

        if (inputPath == "ExitMain")
        {
            std::cout << "****ChangeFileName over****!" << std::endl;
            break;
        }

        // 实例化修改文件名称
        FindUpDate f1(inputPath);

        // 批量修改文件名称
        f1.ChangeFileName();

        std::cout << "************************************************" << std::endl;
    }

    return 0;
}