#include <bits/stdc++.h>
using namespace std;

int nV,nE,start; // So dinh, so canh
vector<int> adj[100]; // Luu danh sach ke
bool visited[100];

void BFS(int u);

int main()
{
    cin >> nV >> nE >> start;
    
    for(int i = 0; i < nE; i++)
    {
        int x,y;
        cin >> x >> y;
        
        adj[x].push_back(y);
        adj[y].push_back(x); // Co vector thi bo
    }
    memset(visited,false,sizeof(visited));

    BFS(start);
    
    return 0;
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while(!q.empty())
    {
        int v = q.front(); // Lay dinh dau hang doi
        q.pop();
        cout << v << " ";
        
        for(int x : adj[v])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }

    }
}
