#include<iostream>
#include"Person.h"
using namespace std;
int main()
{
    Person person(1321231,1970,5,5);
    
    cout << "birth year before the change is:" << person.getBirthDate()->getYear() << endl;

    Date *pDate = person.getBirthDate();
    pDate->setYear(2000);
    cout << "birth year after the change is:" << person.getBirthDate()->getYear() << endl;
    return 0;

}