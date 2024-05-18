#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k, tmp;
    cin >> n >> k;
    
    queue<int> q;
    
    while(n--)
    {
        cin >> tmp;
        q.push(tmp);
    }
    
    while(k--)
    {
        q.push(q.front());
        q.pop();
    }
    
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
