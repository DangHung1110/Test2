#include "MyString.h"

template <typename T>
size_t MyString<T>::getLength(const T* str) const {
    size_t len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

template <typename T>
void MyString<T>::copyString(T* dest, const T* src) {
    size_t i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

template <typename T>
int MyString<T>::compareString(const T* str1, const T* str2) const {
    size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        ++i;
    }
    return str1[i] - str2[i];
}

template <typename T>
MyString<T>::MyString() : data(new T[1]{'\0'}), length(0) {}

template <typename T>
MyString<T>::MyString(const T* str) {
    length = getLength(str);
    data = new T[length + 1];
    copyString(data, str);
}

template <typename T>
MyString<T>::MyString(const MyString<T>& other) {
    length = other.length;
    data = new T[length + 1];
    copyString(data, other.data);
}

template <typename T>
MyString<T>::~MyString() {
    delete[] data;
}

template <typename T>
MyString<T>& MyString<T>::operator=(const MyString<T>& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new T[length + 1];
        copyString(data, other.data);
    }
    return *this;
}

template <typename T>
MyString<T> MyString<T>::operator+(const MyString<T>& other) const {
    MyString<T> result;
    result.length = length + other.length;
    result.data = new T[result.length + 1];
    copyString(result.data, data);
    size_t i = length;
    for (size_t j = 0; j < other.length; ++j, ++i) {
        result.data[i] = other.data[j];
    }
    result.data[i] = '\0';
    return result;
}

template <typename T>
MyString<T>& MyString<T>::operator+=(const MyString<T>& other) {
    *this = *this + other;
    return *this;
}

template <typename T>
bool MyString<T>::operator==(const MyString<T>& other) const {
    return compareString(data, other.data) == 0;
}

template <typename T>
bool MyString<T>::operator!=(const MyString<T>& other) const {
    return !(*this == other);
}

template <typename T>
bool MyString<T>::operator<(const MyString<T>& other) const {
    return compareString(data, other.data) < 0;
}

template <typename T>
bool MyString<T>::operator>(const MyString<T>& other) const {
    return compareString(data, other.data) > 0;
}

template <typename T>
bool MyString<T>::operator<=(const MyString<T>& other) const {
    return compareString(data, other.data) <= 0;
}

template <typename T>
bool MyString<T>::operator>=(const MyString<T>& other) const {
    return compareString(data, other.data) >= 0;
}

template <typename T>
T& MyString<T>::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& MyString<T>::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
ostream& operator<<(ostream& os, const MyString<T>& str) {
    os << str.data;
    return os;
}

template <typename T>
istream& operator>>(istream& is, MyString<T>& str) {
    char arr[1000];
    is >> arr;
    str = MyString<T>(arr);
    return is;
}
