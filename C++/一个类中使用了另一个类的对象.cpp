#include<iostream>

using namespace std;

class A{
public:
    void set(int i, int j)
    {
        x = i;
        y = j;
    }
    int get_y()
    {
        return y;
    }
private:
    int x,y;
};
class  box
{
private:
    int length,width;
    A label;
public:
    void set(int l,int w,int s, int p)
    {
        length = l;
        width = w;
        label.set(s,p);
    }
    int get_area()
    {
        return length * width;
    }
};

int main(int arg, char *argv[])
{
    box b;
    b.set(4,6,1,120);
    cout << b.get_area() << endl;
    return 0;
}