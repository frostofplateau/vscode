#include<iostream>
using namespace std;
int main()
{
    int a = 9;
    int *p = &a;
    cout << "the place of a is:" << p << endl;
    cout << "the place of p is:" << &p << endl;
    cout << (p + 1) << endl;
    //将十六进制的数转换成十进制的数。
    // char *str = cin.getline();
    // cout << str << endl;
    //上面用法有误
    char str1[12]; 
    //若使用char *str;是不行的
    cout << "Enter your string: ";
    cin.getline(str1, 12, '\n');
    cout << "Your enter is:" << str1 << endl;

    size_t b = 2;
    cout << "b is " << b << endl;
    return 0;
}