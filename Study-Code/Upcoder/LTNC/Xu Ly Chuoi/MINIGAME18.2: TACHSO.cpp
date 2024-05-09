#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stringstream ss(str);
    
    string tmp;
    vector<string> vt;
    while(getline(ss,tmp,','))
    {
        vt.push_back(tmp);
    }
    int sum = 0;
    for(int i = 0; i < vt.size(); i++)
    {
        cout << vt[i] << "\n";
        sum += stoi(vt[i]);
    }
    cout << sum; 
    return 0;
}
