#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string &s) {
        char temp = s[0];
        int length = s.size();
        for(int i =0; i < length - 1; i++)
        {
            s[i] = s[length-i-1];
            s[length-i-1] = temp;
            temp = s[i+1];
        }
        return 0;
    }
    
};
int main()
{
    Solution so;
    string str = "asafa";
    so.reverseOnlyLetters(str);
    
    cout << str << endl;
}