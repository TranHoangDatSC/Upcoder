#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a(0), b(0);
    cin >> n;
    vector<int> vt;
    
    while(n > 0)
    {
        vt.push_back(n % 10);
        n /= 10;
    }
    
    sort(vt.begin(), vt.end());
    
    for(int i = 0; i < vt.size(); i++)
    {
        if(i & 1) 
            a = a*10 + vt[i];
        else
            b = b*10 + vt[i];
    }
    cout << a + b;
    return 0;
}
