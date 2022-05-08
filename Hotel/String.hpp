#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED
#include <iostream>

const size_t default_cap = 16;

class String
{
private:
    char* str;
    size_t capacity;

    char* cpy(const char* , size_t ) const;
    void Resize(size_t );

public:
    String();
    String(const char* other);
    String(const String& other);
    String& append(const char*);
    String& append(const String&);
    String& operator=(const String& other);
    String& operator+=(const String&);
    bool operator==(const char*) const;
    ~String();

    friend std::ostream& operator<<(std::ostream&, const String&);
    size_t size_str() const;
    size_t size_capacity() const;
    void Erase();
    void PushBack(char );
    void get_line();


};

#endif // STRING_HPP_INCLUDED
