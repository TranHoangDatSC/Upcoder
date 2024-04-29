#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
    string str;
    int size;
    int i = 0;
    
    cin >> size >> str;
    
    while(i < size)
    {
        if(str[i] == '1')
        {
            i++;
            while(i < size && isalpha(str[i]))
            {
                cout << str[i++];
            }
            cout << " ";
        }
        else if (str[i] == '2')
        {
            i++;
            int begin = i;
            while(i < size && isalpha(str[i]))
            {
                i++;
            }
            for(int j = i - 1; j >= begin; j--)
            {
                cout << str[j];
            }
            cout << " ";
        }
    }
    return 0;
}
