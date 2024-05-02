#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int input;
    std::vector<int> numbers;
    int index = 0;
    
    while(cin >> input)
    {
        numbers.push_back(input);
        index++;
    }
    
    for(int i = 0; i < index; i++)
    {
        cout << *(numbers.begin() + i) << " ";
    }
    cout << '\n';
    for(int i = 0;i < index; i++)
    {
        cout << *(numbers.rbegin() + i) << " ";
    }
    
    return 0;
}
