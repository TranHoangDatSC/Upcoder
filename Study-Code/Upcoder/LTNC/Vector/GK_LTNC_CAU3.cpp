#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// khong su dung ham sort;

int main()
{
    int a, b;
    cin >> a >> b;
    
    vector<int> u(a), v(b);
    
    for(int &x : u) cin >> x;
    for(int &x : v) cin >> x;
    
    
    for(int i = 0; i < a; i++)
    {
        for(int j = i + 1; j < a; j++)
        {
            if(u[i] > u[j]) swap(u[i],u[j]);
        }
    }
    
    for(int i = 0; i < b; i++)
    {
        for(int j = i + 1; j < b; j++)
        {
            if(v[i] > v[j]) swap(v[i],v[j]);
        }
    }
    
    u.erase(remove_if(u.begin(), u.end(), [](int x) { 
        return (int) sqrt(x) == sqrt(x);
    }), u.end());
    
    v.erase(remove_if(v.begin(), v.end(), [](int x) { 
        return (int) sqrt(x) == sqrt(x);
    }), v.end());
    
    
    //hop
    vector<int> res(u.size() + v.size());
    merge(u.begin(), u.end(),v.begin(),v.end(), res.begin());
    
    for(auto x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
    
    res.clear();
    
    // giao
    for(int x : u)
    {
        if(find(v.begin(),v.end(), x) != v.end())
            res.push_back(x);
    }
    
    for(auto x : res)
    {
        cout << x << " ";
    }
    
    return 0;
}
