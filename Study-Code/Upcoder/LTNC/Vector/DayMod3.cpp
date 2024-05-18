#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    cin >> n;
    
    vector<int> vt(n);
    for(int &x : vt)
    {
        cin >> x;
    }
    
    cin >> m;
    
    sort(vt.begin(),vt.end(),[](int a, int b)
    {
        int a_mod = a % 3;
        int b_mod = b % 3;
        
        if(a_mod == 0)
            a_mod = 3;
        if(b_mod == 0)
            b_mod = 3;
            
        if(a_mod != b_mod) 
            return a < b;
    });
    
    if(m >= n)
        cout << "Khong Tim Thay";
    else 
        cout << vt[m];
    
    return 0;
}
