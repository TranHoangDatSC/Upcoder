#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int,int>> edge; // Luu danh sach canh
int adj[1001][1001];
vector<int> vt[1001];

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
            if(adj[i][j])
                vt[i].push_back(j);
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(auto x : vt[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

