#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string n;
    
    getline(cin,str);
    getline(cin,n);
    
    int pos = str.find(n);
    cout << (pos != string::npos ? pos : 0);
    
    return 0;
}
