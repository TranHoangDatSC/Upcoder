#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool check(string str)
{
    stack<char> st;
    
    for(auto x : str)
    {
        if(st.empty() || x != st.top())
            st.push(x);
        else if(st.top() == x) 
            st.pop();
    }
    return st.empty();
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    string str;
    vector<string> vt;
    
    while(n--)
    {
        cin >> str;
        if(check(str))
            vt.push_back(str);
    }
    
    cout << vt.size() << "\n";
    
    for(auto x : vt)
    {
        cout << x << "\n";
    }
    return 0;
}
