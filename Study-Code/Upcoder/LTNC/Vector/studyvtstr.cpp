#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    vector<int> vt;
    int n;
    
    while(cin >> n)
    {
        vt.push_back(n);
    }
    cin.clear();
    /*
    for(int i = 0; i < vt.size(); i++)
    {
        cout << n << " ";
    }
    */
    
    /*
    for(int x : vt)
    {
        cout << n << " ";
    }
    */
    
    /*
    for(vector<int>::iterator it = vt.begin(); it != vt.end(); ++it)
    {
        cout << *it << " ";
    }
    */
    
    for(auto it = vt.begin(); it != vt.end(); ++it)
    {
        cout << *it << " ";
    }
    
    string str;
    getline(cin,str);
    
    stringstream ss(str);
    vector<string> vts;
    
    string tmp;
    while(ss >> tmp)
    {
        vts.push_back(tmp);
    }
    for(string x : vts)
    {
        cout << x << " ";
    }
    return 0;
}
