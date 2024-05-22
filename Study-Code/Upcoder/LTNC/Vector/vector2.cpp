#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    
    stringstream ss(str);
    vector<int> del;
    vector<int> vt;
    int tmp;
    while(ss >> tmp)
    {
        del.push_back(tmp);
    }
    
    if(str.size() < 3)
    {
        int a = del[0];
        
        int n;
        
        while(cin >> n)
            vt.push_back(n);
        
        if(a == -1) 
            vt.clear();
        else 
            vt.erase(vt.begin() + a);
    }
    else
    {
        int a = del[0];
        int b = del[2];
        
        int n;
        while(cin >> n)
            vt.push_back(n);
            
        vt.erase(vt.begin() + a, vt.end() + b - 1);
    }
    
    if(!vt.empty())
        for(auto x : vt)
            cout << x << " ";
            
    else
        cout << "empty";
    return 0;
}
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<int> pos;

    if(str.size() < 3)
    {
        int a = str[0] - 48;
        int n;

        while (cin>>n) 
        {
            pos.push_back(n);
        }

        if(str[0] != '-') 
            pos.erase(pos.begin() + a);
        else 
            pos.clear();
    }

    else 
    {
        int a = str[0] - 48;
        int b = str[2] - 48;

        int n;

        while (cin>>n) 
        {
            pos.push_back(n);
        }

        pos.erase(pos.begin() + a, pos.begin() + b);
    }

    if(!pos.empty())
    {
        for (int i=0;i < pos.size(); i++)
            cout << pos[i] << " ";
    }
    else cout << "empty";

    return 0;
}
*/
