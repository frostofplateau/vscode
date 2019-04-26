#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    
    ofstream output;
    output.open("formattedScores.txt");

    output << setw(20) << "Iwanttofindajobr." << setw(5)
           << 99 << setw(2)
           << 'T' << endl;
    output << setw(20) << "Ihavenideaoutoca." << setw(5)
           << 59  << setw(2) << 'K';//这里有没有换行对以后的操作会有影响：读文件。
           
    cout << "Done!";
    output.close();
    return 0;
}
   