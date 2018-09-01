#include<iostream>
// #include<ctime>
// //#include<stdio.h>
// using namespace std;
// int main()
// {
//     srand(time(0));
//     int a = rand();
//     int aa;
//     //scanf("input a number: %d", &aa);

//     printf("a is %d", a);
//     return 0;
// }


using namespace std;
void t1();
void t2();

int main()
{
    t1();
    t2();
    return 0;
}

int y;
void t1()
{
    int x = 1;
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
    x++;
    y++;
}

void t2()
{
    int x = 1;
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
}