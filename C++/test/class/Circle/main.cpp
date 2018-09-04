#include<iostream>
#include"circle.h"
using namespace std;
/*
------------------------------------------------------
这里可能需要编写makefile文件方能运行含有多个文件的的C++程序

可我不会makefile
故只能使用命令行了
-------------------------------------------------------
*/
int main()
{
    Circle circle1;
    //创建一个对象的时候，调用构造函数，这个会调用无参构造函数
    Circle circle2(4.2);
    //这个会调用有参数的构造函数
    cout << "The area of circle1 of radius " << circle1.getRadius() << " is " << circle1.getArea() << endl;
    cout << "The area of circle2 of radius " << circle2.getRadius() << " is " << circle2.getArea() << endl;
    circle1.setRadius();
    cout << "set circle1 radius is " << circle1.getRadius() << endl;
    circle2.setRadius();
    cout << "set circle2 radius is " << circle2.getRadius() << endl;

    return 0;
}