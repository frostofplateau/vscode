#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    cout << "Enter a number:";
    istream_iterator<int> inputIterator(cin);
    ostream_iterator<int> outputIterator(cout);

    int number = *inputIterator;
    cout << "Output your number:";
    *outputIterator = number;

    return 0;
}