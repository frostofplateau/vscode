#include<iostream>

class Base
{
public:
    Base(const char* p_szName):m_szName(p_szName){std::cout << m_szName << ",";}
    virtual ~Base(){std::cout << "~" << m_szName << ",";}
private:
    const char* m_szName;
};

class Derived:public Base
{
public:
    Derived(const char* p_szName):m_szName(p_szName),m_objA((const char*) "A"),m_objB((const char*)"B"),Base((const char*)"C")
    {
        std::cout << m_szName << ",";
    }
    virtual ~Derived()
    {
        std::cout << "~" << m_szName <<",";
    }
private:
    const char * m_szName;
    Base m_objB;
    Base m_objA;
};


int main()
{
    Base* p = new Derived("D");
    // Base* p = new Base("D");
    // Derived * p = new Derived("D");
    //这个和Base * p = new Derived("D");
    //结果一样
    delete p;
    return 0;
}

//先调用基类的构造函数，再调用对象成员构造函数，再调用子类的构造函数