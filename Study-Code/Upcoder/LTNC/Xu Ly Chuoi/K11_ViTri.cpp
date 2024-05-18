#include <string>
#include <iostream>
using namespace std;

int main()
{
    string str;
    char n;
    
    getline(cin,str);
    cin >> n;
    
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == n)
            cout << i << " ";
    }
    
    return 0;
}
