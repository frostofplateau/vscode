#include<iostream>
using namespace std;
int main()
{
    int x = 1;
    const int *p = &x;
    int y,z;
    int const *q = &x;
    int *const r = &x;
    p = &y;
    q = &z;
    //r = &z;
    //*p = 4;
    //*q = 8;
    //就是说int const和const int是一样的。
    x = 5;
    //指针指向的常量是不能修改的，但是这个变量是可以修改的。

    cout << "x is " << x << endl;
    return 0;
}