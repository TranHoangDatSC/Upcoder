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
        vt.push_back(tmp);
    }
    int cnt = 0;
    for(int i = 0; i < vt.size() - 1; i++)
    {
        cout << vt[i] << " ";
        cnt++;
    }
    cout << "\nSo chu la " << cnt;
    return 0;
}
