#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n;
    vector<string> vt(n);
    
    for(auto &x : vt)
        cin >> x;
        
    cin >> q;
    
    string tmp;
    while(q--)
    {
        cin >> tmp;
        cout << count(vt.begin(),vt.end(), tmp) << "\n";
    }
    
    return 0;
}
