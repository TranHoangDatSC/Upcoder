#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    while(n--)
    {
        string str;
        getline(cin,str);
        for(int i = 0;i < str.size(); i++)
        {
            str[i] = tolower(str[i]);
        }
        vector<string> vt;
        stringstream ss(str);
        
        string tmp;
        while(ss >> tmp)
        {
            vt.push_back(tmp);
        }
        cout << vt[vt.size() - 1]; // cout << vt.back();
        for(int i = 0; i < vt.size() - 1; i++)
        {
            cout << vt[i][0];
        }
        cout << "@gmail.com\n";
    }
    return 0;
}
