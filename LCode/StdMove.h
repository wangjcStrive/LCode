#pragma once
/*
	��/��ֵ���á�
	�ƶ����캯�����ƶ���ֵ���캯����
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class MyString
{
public:
    static size_t CCtor; //ͳ�Ƶ��ÿ������캯���Ĵ���
    static size_t MCtor; //ͳ�Ƶ����ƶ����캯���Ĵ���
    static size_t CAsgn; //ͳ�Ƶ��ÿ�����ֵ�����Ĵ���
    static size_t MAsgn; //ͳ�Ƶ����ƶ���ֵ�����Ĵ���

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

    //���ƹ��캯��
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

    // �ƶ����캯��
    MyString(MyString&& str) noexcept : m_data(str.get_c_str())
    {
        MCtor++;
        str.set_c_str();
    }
    // �ƶ���ֵ =����
    MyString& operator=(MyString&& str) noexcept
    {
        MAsgn++;
        if (this == &str) // �������Ҹ�ֵ!!
            return *this;

        delete[] m_data;
        m_data = str.m_data;
        str.m_data = nullptr; //����ָ��֮ǰ����Դ��
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