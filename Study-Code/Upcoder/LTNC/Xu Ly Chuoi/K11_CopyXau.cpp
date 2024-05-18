#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int n,m;
    
    getline(cin,str);
    cin >> n >> m;
    
    if(n < 0 || m >= str.size())
        cout << "gioi han khong dung";
    else
        cout << str.substr(n,m - n+1);
        
    return 0;
}
