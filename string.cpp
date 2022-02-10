#include "string.h"
#include <string>
#include <cstring>
#include <cassert>

String::String()
{
    m_str = nullptr;
    m_size = 0;
}

String::String(const char* str)
{
    m_size = len(str);
    m_str = new char[m_size + 1];
    m_str[m_size] = '\0';

    for (int i = 0; i < m_size; ++i)
    {
        m_str[i] = str[i];
    }
}

String::String(const String& str)
	:m_str(nullptr)
{
    *this = str;
}

String::~String()
{
    delete[] m_str;
}

bool String::is_empty() const
{
    return m_size == 0 || m_str == nullptr;
}

int String::strcmp(const char * s1, const char * s2)  
{
    int it = 0;
    while(s1[it] != '\0' && (s1[it] == s2[it]))
    {
        it++;
    }
    return (const unsigned char)s1[it] - (const unsigned char)s2[it]; 
}

int String::len(const char* str) const
{
    if(is_empty()){
    return 0; 
    }
    int count = 0;
    while (str[count++] != '\0') {}

    return count - 1;
}

void String::append(const String& str)
{
	*this += str; 
							
}

const String& String::operator=(const String& str)
{
    m_size = str.m_size;
    if (!is_empty())
   	 delete[] m_str;

    m_str = new char[m_size + 1];
    m_str[m_size] = '\0';

    for (int i = 0; i < m_size; ++i)
    {
        m_str[i] = str.m_str[i];
    }
    return *this;
}

String String::operator+(const String& str) const
{
    String result;

    result.m_size = m_size + str.m_size;

    result.m_str = new char[result.m_size + 1];

    result.m_str[result.m_size] = '\0';

    int i;

    for (i = 0; i < m_size; ++i)
    {
        result.m_str[i] = m_str[i];
    }

    int j = 0;

    for (i = m_size; i < result.m_size; ++i)
    {
        result.m_str[i] = str.m_str[j++];
    }

    return result;
}

const String& String::operator+=(const String& str)
{
    *this = *this + str;

    return *this;
}

bool String::operator<(const String& str) const
{
    return strcmp(m_str, str.m_str) < 0;
}

char& String::operator[](int index)
{
    assert(!is_empty() && valid_index(index));
    return m_str[index];
}

bool String::valid_index(int index) const
{
    return (index >= 0 && index < m_size);
}

const char& String::operator[](int index) const
{
    assert(!is_empty() && valid_index(index));
    return m_str[index];
}

void String::swap(String& str)
{
    String temp = *this;

    *this = str;

    str = temp;
}

int String::find_first_of(const char* str)
{
    int str_len = len(str);
    int res_index = -1;
   
    for (int i = 0; i < m_size; ++i)
    {
	int j;
        for (j = 0; j < str_len; ++j)
        {
            if ((i + j < m_size) && (m_str[i + j] != str[j]))
            {
                break;
            }
        }
        
        if (j == str_len)
        {
            return i;
        }
    }
    return -1;
}

std::ostream & operator<<(std::ostream& out, const String& str)
{
    for (int i = 0; i < str.m_size; ++i)
    {
        out << str.m_str[i];
    }
    return out;
}

