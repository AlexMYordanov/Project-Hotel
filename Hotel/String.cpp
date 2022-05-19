#include "String.hpp"
#include <cstring>


char* String::cpy(const char* other, size_t _capacity) const
{
    char* result = new char[_capacity + 1];
    strcpy(result, other);

    return result;
}

String::String() : capacity(default_cap)
{
    str = new char[capacity + 1];
    str[0] = 0;
}

String::String(const char* other) : capacity(default_cap)
{
    size_t str_size = strlen(other);

    while((capacity*3)/4 < str_size )
    {
        capacity *= 2;
    }

    str = cpy(other, capacity);
}

String::String(const String& other): capacity(other.capacity)
{
    str = cpy(other.str, capacity);
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        delete[] str;
        capacity = other.capacity;
        str = cpy(other.str, capacity);
    }

    return *this;
}


String::~String()
{
    delete[] str;
}

size_t String::size_str() const
{
    return strlen(str);
}

size_t String::size_capacity() const
{
    return capacity;
}

std::ostream& operator<<(std::ostream& os, const String& _str)
{
    os<<' '<< _str.str;
    return os;
}
String& String::append(const char* other)
{
    bool flag = false;
    while ((capacity*3)/4 < strlen(other) + size_str())
    {
        flag = true;
        capacity *= 2;
    }

    if(flag)
    {
        Resize(capacity);
    }

    strcat(str, other);

    return *this;
}
String& String::append(const String& other)
{
    return append(other.str);
}
String& String::operator+=(const String& other)
{
    return append(other);
}

void String::Resize(size_t capacity)
{
    char* temp = str;
    str = new char[capacity + 1];
    strcpy(str, temp);
    delete[] temp;
}

bool String::operator==(const char* other) const
{
    return  strcmp(str, other)== 0 ;
}


void String::Erase()
{
    if(capacity != default_cap)
    {
        delete[] str;
        capacity = default_cap;
        str = new char[capacity + 1];
    }
    else
    {
        str[0] = 0;
    }
}
void String::PushBack(char c)
{
    if((capacity*3)/4 < size_str() + 1)
    {
        capacity *= 2;
        Resize(capacity);
    }

    size_t original_size = size_str();
    str[original_size] = c;
    str[original_size + 1] = 0;
}

void String::get_line()
{

    char c;
    for(;;)
    {
        std::cin.get(c);
        if(c=='\n')
            break;
        else
           PushBack(c);
    }

}












