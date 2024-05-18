#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    string str = "abcdef";
    queue<char> q;
    
    cin >> n;
    
    for(char c : str)
    {
        q.push(c);
    }
    
    while(n--)
    {
        q.push(q.front());
        q.pop();
    }
    
    while(!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    return 0;
}
