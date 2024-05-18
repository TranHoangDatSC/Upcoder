#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    
    list<int> lst;
    
    while(n--)
    {
        cin >> tmp;
        lst.push_back(tmp);
    }
    
    auto it = lst.begin();
    
    advance(it, lst.size() / 2);
    
    while(it != lst.end())
    {
        cout << *it << " ";
        it++;
    }
    
    return 0;
}
