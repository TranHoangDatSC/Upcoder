#include <bits/stdc++.h>
using namespace std;

int nV, nE, start; // Số đỉnh, số cạnh
vector<int> adj[100]; // Danh sách kề
bool visited[100]; // Đánh dấu

void DFS(int u); // Hàm DFS

int main()
{
    cin >> nV >> nE >> start;
    
    for(int i = 0; i < nE; i++)
    {
        int x,y;
        cin >> x >> y;
        
        adj[x].push_back(y);
        adj[y].push_back(x); // Vector có hướng thì bỏ
    }
    
    memset(visited,false,sizeof(visited)); // Đảm bảo toàn bộ visited đều false
    DFS(start);
    
    return 0;
}

void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            DFS(v);
        }
    }
}

/* Nếu là đồ thị có hướng:
Input:
6 6 1
1 2
1 3
1 5
2 4
3 5
6 5

Output:
1 2 4 3 5
*/
