#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string str;
    vector<string> vt;
    while(n--)
    {
        cin >> str;
        
        if(find(vt.begin(),vt.end(),str) == vt.end())
            cout <<"OK\n";
            
        else 
            cout << str << count(vt.begin(),vt.end(), str) << "\n";
        
        vt.push_back(str);
    }
    return 0;
}
