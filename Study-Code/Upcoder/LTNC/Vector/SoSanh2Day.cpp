#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void stov(string str, vector<int> &v)
{
    string tmp;
    stringstream ss(str);
    
    while(getline(ss,tmp,','))
    {
        v.push_back(stoi(tmp));
    }
}

int main()
{
    int res;
    string s1, s2;
    vector<int> v,a,b;
    
    getline(cin,s1);
    getline(cin,s2);
    
    stov(s1,a);
    stov(s2,b);
    
    sort(a.begin(),a.end());
    res = a.back();
    
    for(int x : a)
    {
        if(find(b.begin(),b.end(),x) == b.end())
            res = min(res,x);
    }
    
    if(find(b.begin(), b.end(),res) == b.end())
        cout << res << "\n";
        
    else cout << "khong co\n";
    
    for(int x : a)
    {
        if(find(b.begin(),b.end(),x) != b.end() && 
        count(v.begin(), v.end(), x) == 0)
            v.push_back(x);
    }
    
    if(v.size() > 0)
    {
        cout << v.size() << "\n";
        for(int i = 0; i < v.size(); i++)
        {
            cout << (i == 0 ? "" : ",");
            cout << v[i];
        }
    }
    else cout <<"khong co";
    
    return 0;
}
