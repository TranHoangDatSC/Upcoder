#include <bits/stdc++.h>
using namespace std;

int n, m, min_way; // n dong m cot, duong di ngan nha
int xA, xB, yA, yB;

char arr[100][100];

vector<pair<int,int>> res,way;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void Try(int x,int y);

int main()
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        
            if(arr[i][j] == 'A')
            {
                xA = i;
                yA = j;
            }
            if(arr[i][j] == 'B')
            {
                xB = i;
                yB = j;
            }
        }
    }
    min_way = n*m;
    way.push_back({xA,yA});
    
    Try(xA,yA);
    
    cout << min_way << "\n";
    
    for(auto p : res)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    return 0;
}

void Try(int x, int y)
{
    if(x == xB && y == yB)
    {
        if(way.size() < min_way)
        {
            min_way = way.size();
            res = way;
        }
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            int xMoi = x + dx[i];
            int yMoi = y + dy[i];
            
            if(1 <= xMoi && xMoi <= n && 1 <= yMoi && yMoi <= m 
            && arr[xMoi][yMoi] != '*')
            {
                char tmp = arr[xMoi][yMoi];
                
                arr[xMoi][yMoi] = '*';
                way.push_back({xMoi,yMoi});
                
                Try(xMoi,yMoi);
                
                arr[xMoi][yMoi] = tmp;
                way.pop_back();
            }
        }
    }
}
