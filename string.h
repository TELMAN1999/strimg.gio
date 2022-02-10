#ifndef STRING_H
#define STRING_H

#include <ostream>

class String
{
public:
    String();
    String(const char*);
    String(const String & str);
    ~String();

public:
    inline int get_size() const { return m_size; }
    void append(const String & str);
public:
    const String & operator=(const String & str);
    String operator+(const String & str) const;
    const String & operator+=(const String & str);
    static int strcmp(const char *, const char *);
    bool operator<(const String & str) const;
    friend std::ostream &operator<<(std::ostream& out, const String& str);
    operator const char *() const { return m_str; }
    bool valid_index(int index) const;

    char & operator[](int index);
    const char & operator[](int index) const;

    void swap(String & str);
    int find_first_of(const char* str);

    bool is_empty() const;

private:
    int len(const char* str) const;

private:
    char* m_str;
    int m_size;
};

#endif
