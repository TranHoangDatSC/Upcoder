#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, tmp;
    cin >> n;
    
    vector<int> vt(n);
    for(int &x : vt)
    {
        cin >> x;
    }
    
    cin >> q;
    while(q--)
    {
        cin >> tmp;
        auto it = lower_bound(vt.begin(), vt.end(), tmp);
        
        cout << (vt[it - vt.begin()] == tmp ? "Yes " : "No ");
        cout << it - vt.begin() + 1 << "\n";
    }
    return 0;
}
