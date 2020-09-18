#include<iostream>
using namespace std;
class A
{
public:
    A(){}
    ~A(){cout<<"~A"<<endl;}
};
class B : public A
{
    public:
    B(A &a):_a(a)//a给_a赋值
    {
        
    }
    ~B(){cout<<"~B"<<endl;}
    private:
    A _a;
};
int main(void)
{
    A a;
    B b(a);
}