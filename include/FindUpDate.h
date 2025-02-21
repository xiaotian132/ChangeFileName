#pragma once

#include <iostream>
#include <string>
#include <dirent.h>
#include <cstring>

class FindUpDate
{
public:
    //*******************构造函数与析构函数***********************//

    /*
    函数名称:       构造函数
    path:           文件夹路径
    */
    FindUpDate(std::string path);

    /*
    函数名称:       析构函数
    */
    ~FindUpDate();

    //***********************功能函数****************************//

    /*
    函数名称:       修改路径下文件名称
    */
    void ChangeFileName();

private:
    // 输入路径
    std::string m_Path;
};