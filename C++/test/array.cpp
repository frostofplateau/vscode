#include<iostream>
using namespace std;
int main()
{
    int abc[10] {2,23,23,42};
    cout << abc[0];
    cout << "ÔõÃ´ÊÇÂÒÂëÄØ"<< endl;

    int a = 10;
    int &b = a;
    cout << " a is " << &a << endl
         << " b is " << &b << endl;

    return 0;
    
}