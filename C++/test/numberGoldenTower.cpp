#include<iostream>
using namespace std;
int main()
{
    cout << "Enter a number between 1 and 12:" << endl;
    int numberOfLine;
    cin >> numberOfLine;


    for(int row = 1; row <= numberOfLine; row ++){
        
        for (int column = 1; column <= numberOfLine - row; column ++){
            cout << "   ";
        }
        for (int num = row; num >= 1; num --){
            cout << ((num >= 10) ? " " : "  ") << num;

        }
        for (int num = 2; num <= row; num ++){
            cout << ((num >= 10) ? " " : "  ") << num;
        }
        cout << endl;
    }
    return 0;
}