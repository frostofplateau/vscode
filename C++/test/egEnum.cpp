#include<iostream>
using namespace std;
int main()
{
    enum Day
    {
        MONDAY = 1,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY
    } day;
    cout << "Enter a day (1 for MONDAY, 2 for TUESDAY, etc): ";
    int dayNumber;
    cin >> dayNumber;
    switch(dayNumber) {
        case MONDAY :
            cout << "Play soccer" << endl;
            break;
        case TUESDAY :
            cout << "Piano lesson" << endl;
            break;
        default :
            cout << "Go home." << endl;
    }
    return 0;
}

//I want to know what this episode of code show to users!