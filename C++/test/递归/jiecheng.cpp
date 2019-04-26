#include<iostream>
#include<cstring>
using namespace std;
int resursive(int);//阶乘
int fib(int);//斐波那契数列
int main()
{
    // char a[] = "sdasdfasdf";
    // cout << strlen(a);
    //这种形式也是正确的。应该是不太清楚strlen这个函数的原因，才有点怀疑的吧。

    cout << "Enter the number:";
    int number;
    cin >> number;
    int result = resursive(number);
    cout << "the result is " << result << endl;

    cout << "the fib is:";
    for (int i = 0; i < 10;i++)
    {
        cout << fib(i) << " ";
    }
        return 0;
}

int resursive(int n)
{
    if(n == 0)
        return 1;
    else if(n == 1)
        return 1;
    else
        return(n * (resursive(n - 1)));

}
int fib(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;

    else return (fib(n - 1) + fib(n-2));
}