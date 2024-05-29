#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    int _n = n;
    vector<int> vt_n;
    
    string str;
    vector<string> vt;
    while(cin >> str)
    {
        vt.push_back(str);
    }
    
    for(int i = 0; i < vt.size(); i++)
    {
        
        if(vt[i] == "reset")
        {
            _n = n;
            cout << _n << " ";
        }
        if(vt[i] == "plus1")
        {
            _n += 1;
            cout << _n << " ";
        }
        if(vt[i] == "minus1")
        {
            _n -= 1;
            cout << _n << " ";
        }
    }
    return 0;
}
