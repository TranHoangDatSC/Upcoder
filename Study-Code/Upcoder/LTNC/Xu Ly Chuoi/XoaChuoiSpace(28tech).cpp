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
    
    string word;
    cin >> word;
    
    string tmp;
    vector<string> vt;
    while(ss >> tmp)
    {
        if(tmp != word)
            vt.push_back(tmp);
    }
    
    for(int i = 0; i < vt.size(); i++)
    {
        cout << vt[i];
        if(i != vt.size() - 1)
            cout << " ";
    }
    return 0;
}
