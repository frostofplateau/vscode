#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    // ofstream output;
    // output.open("test.txt");
    // //output << "This is not a procedure." << endl;
    // output << 12 << " " << 32 << " " << 35 << endl;
    // output.close();

    ifstream input;
    string str;
    int a,b,c;
    //char ch;
    int total = 0;
    input.open("test.txt");
    // input >> b;
    // input >> a;
    // cout << b << endl
    //      << a << endl;

    //当同时打开使用上述代码和下列代码时会出错。
    
    while(!input.eof()){
        input >> c;
        cout << c << endl;
        total += c;
        cout << "#" << total << endl;
    }

    input.close();
    return 0;
}