#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int,int>> edge; // Luu danh sach canh
int adj[1001][1001];

int main()
{
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> adj[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(adj[i][j] && i < j)
                edge.push_back({i,j});
        }
    }
    
    for(auto it : edge)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}

