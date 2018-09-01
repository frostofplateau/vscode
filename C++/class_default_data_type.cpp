#include<iostream>
using namespace std;
class A
{
    //public:
    //类中成员默认的是private
    int a = 656;
    public:
      int fun(int b) { return a+b; }
};
int main(void)
{
    A a;
    cout << a.fun(5);
}