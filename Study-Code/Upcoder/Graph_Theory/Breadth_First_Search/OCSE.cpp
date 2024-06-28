#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
int arr[100][100];
bool visited[100][100];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int BFS(int x,int y);
bool Valid(int y,int x,int n, int m)
{
    return (y >= 1 && y <= n && x >= 1 && x <= m);
}
int main()
{
    cin >> n >> m >> y >> x;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(visited,false,sizeof(visited));
    
    int res = BFS(y,x);
    cout << res;
    
    return 0;
}

int BFS(int u, int v)
{
    queue<pair<int,int>> q;
    q.push({u,v});
    visited[u][v] = true;
    int sum = 0;
    
    while(!q.empty())
    {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        sum++;
        
        for(int i = 0; i < 4; i++)
        {
            int X = xx + dx[i];
            int Y = yy + dy[i];
            
            if(Valid(Y,X,n,m) && !visited[Y][X] & arr[Y][X] == 0)
            {
                q.push({Y,X});
                visited[Y][X] = true;
            }
        }
    }
    return sum;
}
