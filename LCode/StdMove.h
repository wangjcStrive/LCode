#pragma once
/*
	左/右值引用。
	移动构造函数，移动赋值构造函数。
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class MyString
{
public:
    static size_t CCtor; //统计调用拷贝构造函数的次数
    static size_t MCtor; //统计调用移动构造函数的次数
    static size_t CAsgn; //统计调用拷贝赋值函数的次数
    static size_t MAsgn; //统计调用移动赋值函数的次数

public:
    MyString(const char* cstr = 0)
    {
        if (cstr)
        {
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data, cstr);
        }
        else
        {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    //复制构造函数
    MyString(const MyString& str)
    {
        CCtor++;
        m_data = new char[strlen(str.get_c_str()) + 1];
    }
    MyString& operator=(const MyString& str)
    {
        CAsgn++;
        if (this == &str)
        {
            return *this;
        }
        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }

    // 移动构造函数
    MyString(MyString&& str) noexcept : m_data(str.get_c_str())
    {
        MCtor++;
        str.set_c_str();
    }
    // 移动赋值 =重载
    MyString& operator=(MyString&& str) noexcept
    {
        MAsgn++;
        if (this == &str) // 避免自我赋值!!
            return *this;

        delete[] m_data;
        m_data = str.m_data;
        str.m_data = nullptr; //不再指向之前的资源了
        return *this;
    }

    ~MyString()
    {
        delete[] m_data;
    }

    char* get_c_str() const { return m_data; }
    void set_c_str() { m_data == nullptr; }

private:
    char* m_data;
};