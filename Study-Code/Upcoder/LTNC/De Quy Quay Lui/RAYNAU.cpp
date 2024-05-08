#include <iostream>
#include <vector>
using namespace std;

#define MAX 250

struct RayNau
{
    int x, y;
    RayNau(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
vector<RayNau> vt;
int n; // dong
int m; // cot
int sum = 0;
int dientich = 0;
int arr[MAX + 1][MAX + 1];

bool visited[MAX + 1][MAX + 1];

void Try(int i, int j)
{
    if(1 <= i && i <= m && j <= n && 1 <= j && arr[i][j] == 1)
    {
        dientich++;
        visited[i][j] = true;
        vt.push_back(RayNau(i,j));
        
        if(!visited[i-1][j])
            Try(i-1,j);
        if(!visited[i+1][j])
            Try(i+1,j);
        if(!visited[i][j-1])
            Try(i,j-1);
        if(!visited[i][j+1])
            Try(i,j+1);
            
    }
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                sum++;
        }
    }
    cout << sum << "\n";
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!visited[i][j] && arr[i][j] == 1)
            {
                dientich = 0;
                Try(i, j);
            
                cout << dientich << " ";
                
                for(int k = 0; k < vt.size(); k++)
                {
                    cout << "[" << vt[k].x << "," << vt[k].y << "]";
                    if(k < vt.size() - 1)
                        cout << ", ";
                }
                cout << "\n";
                vt.clear();
            }
        }
    }
    return 0;
}
