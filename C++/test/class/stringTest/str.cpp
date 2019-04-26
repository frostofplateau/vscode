#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a = 2;
    int *b = &a;
    int &c = a;

    cout << "a is " << a << " b is " << b
         << " c is " << c << endl;

    string str;
    string str1("sdfasd");
    string &str2 = str;

    str = str1;
    cout << sizeof(str) << str2 << endl;
    cout << str;
    3;
    return 0;
}