#include<iostream>
using namespace std;
template<typename T>
void maxValue(T list[], int arraySize)
{
    for (int i = arraySize - 1; i >= 1; i--)
    {
        int maxValueIndex = 0;
        T currentMax = list[0];
                                                                                                                                                                                                                                                                                                                                                              for (int j = 1; j <= i; j++)
        {
            if(currentMax < list[j])
            {
                currentMax = list[j];
                maxValueIndex = j;
            }
        }
        if(maxValueIndex != 1)
        {
            list[maxValueIndex] = list[i];
            list[i] = currentMax;
        }
    }

    cout << "maxValue is " << list[arraySize - 1] << endl;
    
}
int main()
{
    string str = "abcdefghijklmnopqrstuvwxyz";
    cout << str.data() << endl;
    string str1 = "abc";
    cout << (str.data() > str1.data()) << endl;

    cout << "----------------------------" << endl;
    int list1[]{1, 5, 8, 65, 45};
    //int num = 5;
    maxValue(list1, 5);
    cout << "----------------------------" << endl;
    string list2[]{"Huo","Wen","Ting","Wang","Peng"};

    maxValue(list2, 5);
    cout << "----------------------------" << endl;
    return 0;

}