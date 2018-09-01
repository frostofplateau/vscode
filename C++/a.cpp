#include<iostream>
#include<string>
using namespace std;
int main(){
    cout << "Who Are You?" <<endl;
    string name;
    cin >> name;
    cout << name << endl;
    cout << "Hello," << name << endl;
    int num1, num2;
    char ch;
    cin >> ch;
    cout << endl;
    cin >> num1 >> num2;
    int res;
    switch(ch){
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
    }
    cout << res << endl;
    cout << "Wellcome!";
    cin.get();
    cin.get();
    return 0;

}



//有点卡我的这台电脑真的卡相当的卡很烦
//什么时候能换电脑