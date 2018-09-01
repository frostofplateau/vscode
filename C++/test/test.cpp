#include<iostream>
#include<cstdlib>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    srand(time(0));
    int randomInt = rand() % 10;
    cout << randomInt << endl;
    cout << rand();


    bool b =  true;
    int i =b;
    i = 1;
    b = i;//error
    cout << b << endl << i << endl;


    
    return 0;
}
