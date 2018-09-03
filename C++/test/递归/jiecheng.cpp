#include<iostream>
using namespace std;
int resursive(int);
int main()
{
    cout << "Enter the number:";
    int number;
    cin >> number;
    int result = resursive(number);
    cout << "the result is " << result << endl;
    return 0;
}

int resursive(int n)
{
    if(n == 0)
        return 1;
    else if(n == 1)
        return 1;
    else
        return(n * (resursive(n - 1)));

}