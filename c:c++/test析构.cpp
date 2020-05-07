#include <iostream>

class A
{
public:
    A(){std::cout << "create\n";}
    ~A(){std::cout<<"delete\n";}
    
};

int main()
{
    A *a = new A[5];
    delete[] a;
    return 0;
}
/*
这题主要是区分delete和delete[]

*/