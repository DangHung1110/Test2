#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

template <typename T = char>
class MyString {
private:
    T* data;
    size_t length;

    size_t getLength(const T* str) const;
    void copyString(T* dest, const T* src);
    int compareString(const T* str1, const T* str2) const;

public:
    MyString();
    MyString(const T* str);
    MyString(const MyString<T>& other);
    ~MyString();

    MyString<T>& operator=(const MyString<T>& other);
    MyString<T> operator+(const MyString<T>& other) const;
    MyString<T>& operator+=(const MyString<T>& other);

    bool operator==(const MyString<T>& other) const;
    bool operator!=(const MyString<T>& other) const;

    bool operator<(const MyString<T>& other) const;
    bool operator>(const MyString<T>& other) const;
    bool operator<=(const MyString<T>& other) const;
    bool operator>=(const MyString<T>& other) const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    template <typename U>
    friend ostream& operator<<(ostream& os, const MyString<U>& str);

    template <typename U>
    friend istream& operator>>(istream& is, MyString<U>& str);
};
#endif
