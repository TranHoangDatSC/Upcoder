#include <iostream>
#include <stack>
using namespace std;

bool check(string str)
{
    stack<char> s;
    for(char c : str)
    {
        if(s.empty() || c != s.top())
            s.push(c);
        else s.pop();
    }
    return s.empty();
}

int main()
{
    int n, cnt=0;
    cin >> n;
    
    string res = "";
    
    while(n--)
    {
        string str; 
        cin >> str;
        if(check(str))
        {
            res += str + '\n';
            cnt++;
        }
    }
    cout << cnt << "\n" << res;
    return 0;
}
