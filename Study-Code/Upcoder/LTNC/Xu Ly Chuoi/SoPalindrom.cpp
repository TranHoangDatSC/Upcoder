#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool check(string str)
{
    stringstream ss(str);
    string token;
    string tmp = "";
    
    while(ss >> token)
    {
        tmp += token;
    }
    
    int len = 0, rig = str.size() - 1;
    while(len <= rig)
    {
        if(tmp[len] != tmp[rig])
            return false;
            
        len++;
        rig--;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cin.clear();
    
    vector <string> vt;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        vt.push_back(str);
    }
    for(int i = 0; i < n; i++)
    {
        if(check(vt[i]))
            cout << vt[i] << " ";
    }
    return 0;
}
