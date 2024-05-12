#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string str, token;
    getline(cin,str);
    
    vector<string> vt;
    char kytu;
    cin >> kytu;
    
    for(int i = 1; i < str.size(); i++)
    {
        if(str[i-1] == str[i] && str[i] == kytu)
        {
            str.erase(i,1);
            i--;
        }
    }
    
    if(str[0] == kytu)
        str.erase(0,1);
    if(str[str.size() - 1] == kytu)
        str.erase(str.size() - 1, 1);
        
    stringstream ss(str);
    
    while(getline(ss,token,kytu))
    {
        vt.push_back(token);
    }
    cout << vt.size() << "\n";
    
    for(auto x : vt)
        cout << x << "\n";
    return 0;
}
