#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp;
    
    list<int> lst;
    
    cin >> n;
    while(n--)
    {
        cin >> tmp;
        lst.push_back(tmp);
    }
    
    lst.reverse();
    for(auto x : lst)
    {
        cout << x << " ";
    }
    return 0;
}
