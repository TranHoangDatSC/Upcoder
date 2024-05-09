#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    stringstream ss(str);
    
    string token;
    vector<string> vt;
    while(ss >> token)
    {
        vt.push_back(token);
    }
    cout << vt[0] << "\n";
    for(int i = 1; i < vt.size() - 1; i++)
    {
        cout << vt[i] << " ";
    }
    cout << "\n" << vt.back();
    return 0;
}
