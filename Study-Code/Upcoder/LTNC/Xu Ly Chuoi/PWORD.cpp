#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int res(0);
    cin >> str;
    
    for(char x : str)
    {
        if(isdigit(x))
            res += x - '0';
    }
    cout << res;
    return 0;
}
