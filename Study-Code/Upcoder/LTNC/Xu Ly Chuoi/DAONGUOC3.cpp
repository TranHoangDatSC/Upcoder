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
    
    vector<string> vt;
    string word;
    while(ss >> word)
    {
        vt.push_back(word);
    }
    
    for(int i = vt.size() - 1; i >= 0; i--)
    {
        cout << vt[i];
        if(i != vt.size())
            cout << " ";
    }
    return 0;
}
