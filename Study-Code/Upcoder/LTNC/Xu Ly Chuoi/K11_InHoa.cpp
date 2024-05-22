#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

void Upper(string& str)
{
    for(int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
}

int main()
{
    string str;
    getline(cin,str);
    
    stringstream ss(str);
    vector<string> vt;
    string token;
    
    while(ss >> token)
    {
        vt.push_back(token);
    }
    
    for(int i = 0; i < vt.size(); i++)
    {
        Upper(vt[i]);
        cout << vt[i] << " ";
    }

    return 0;
}
