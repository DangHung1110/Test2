#include "MyString.h"

int main() {
    MyString<char> str1("DangHung");
    MyString<char> str2("Hung");
    MyString<char> str3;

    str3 = str1 + " " + str2;
    cout << "Noi chuoi: " << str3 << endl;

    if (str1 == str2)
        cout << "Hai chuoi bang nhau." << endl;
    else
        cout << "Hai chuoi khong bang nhau." << endl;

    str1[1] = 'a';
    cout << "Chuoi sau khi sua: " << str1 << endl;

    cout << "Nhap mot chuoi: ";
    cin >> str3;
    cout << "Chuoi vua nhap: " << str3 << endl;

    return 0;
}
