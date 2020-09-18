#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    
    ofstream output;
    output.open("fileTest.txt");

    // string str = "I want to find a job recently.";
    // int c = 99;
    // char ch[]{'a', 'b', 'c'};

    output << "Iwanttofindajobr." << " "
           << 99 << " "
           << 'T' << endl;
    output << "Ihavenideaoutoca." << "  "
           << 59  << " " << 'K' << endl;//这里有没有换行对以后的操作会有影响：读文件。
    cout << "Done!";
 output.close();
    return 0;
}
   