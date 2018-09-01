#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    cout << "Compute these calculate follow." << endl;
    while(1){
        int num1, num2;
        
        srand(time(0));
        num1 = rand() % 10;
        num2 = rand() % 10;
        int total = 0;
        // enum cal
        // {
        //     ch1 = '+',
        //     ch2 = '-',
        //     ch3 = '*',
        //     ch4 = '/'
        // } cal;
        //char ch;
        int i = rand()% 4;
        switch(i){
            case 0:
                cout << num1 << "+" << num2 << "=";
                
                cin >> total;
                if(total == num1 + num2)
                    cout << endl << "right" << endl;
                    
                else
                {
                    cout << "error" << endl;
                }
                break;
            case 1:
            cout << num1 << "-" << num2 << "=";
                cin >> total;
                if(total == num1 - num2)
                    cout << "right" << endl;
                    
                else
                {
                    cout << "error" << endl;
                }
            break;
            case 2:
                cout << num1 << "*" << num2 << "=";
                cin >> total;
                if(total == num1 * num2)
                    cout << "right" << endl;
                    
                else
                {
                    cout << "error" << endl;
                }
                break;
            case 3:
                if(num2 != 0){
                    cout << num1 << "/" << num2 << "=";
                
                    cin >> total;
                    if(total == num1 / num2)
                        cout << "right" << endl;
                        
                    else
                    {
                        cout << "error" << endl;
                    }
                    }
                break;

        }
    }
    return 0;
}