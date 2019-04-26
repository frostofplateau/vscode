#include<iostream>
#include<fstream>
// #include<string>
using namespace std;
int main()
{
    ifstream input;
    input.open("fileTest1.txt");

    //检测文件是否打开
    if(input.fail())
    {
        cout << "This file does not exist!" << endl;
    }
    bool isExist = input.fail();

    cout << isExist << endl;

    char str[80]; //这个str好像不能定义为string类型
    //string str;

    int c;
    char ch[80];


    //一样的问题，如果在这里的字符有空格的话，程序是不能正常读取数据的。

    while(!input.eof())
    {
        //检测文件尾
        input >> str >>  c >> ch;
        cout << str << " " << c << " " << ch << endl;
        //这里有个问题，如果文件最后有一个换行符的话，这里会自动再读一遍上一行的内容跟.
    }
    // input >> str >>  c >> ch;
    // cout << str << " " << c << " " << ch << endl;

    
    cout << "Done!";
    input.close();
    return 0;
}