#include<iostream>
using namespace std;
class A
{
    public:
    A()
    {
        cout << "create A." << endl;
    }
    A(const A& other)
    {
        cout << "copy A." << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};
class C
{
    public:
    C()
    {
        cout << "create C" << endl;
    }
    C(const A& other)
    {
        cout << "copy C" << endl;
    }
    ~C()
    {
        cout << "~C" << endl;
    }
};
class B : public A
{
    public:
    B()
    {
        cout << "create B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }
    private:
    C _a;
};
int main(void)
{
    B b;
    cout << "--------------" << endl;
}
