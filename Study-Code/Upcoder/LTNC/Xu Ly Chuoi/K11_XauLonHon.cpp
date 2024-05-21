#include <iostream>
using namespace std;

int main()
{
    string s1,s2;
    
    getline(cin,s1);
    getline(cin,s2);
    
    if(s1 < s2)
        cout << s2;
    else if (s1 > s2)
        cout << s1;
    else cout << "Hai xau bang nhau";
    
    return 0;
}
