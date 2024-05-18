#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string a,b;
    
    getline(cin,a);
    getline(cin,b);
    
    if(a.size() < b.size())
        cout << b;
    else if(a.size() > b.size())
        cout << a;
    else cout << "Hai xau dai bang nhau";
    
    return 0;
}
