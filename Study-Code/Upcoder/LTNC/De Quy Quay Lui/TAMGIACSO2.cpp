#include <bits/stdc++.h>
using namespace std;

int n, maxSum, sum(0);
int arr[100][100];

vector<int> way;
vector<vector<int>> save;

int dx[] = {1,1};
int dy[] = {0,1};

void Try(int x, int y)
{
    if(x == n - 1)
    {
        if(maxSum < sum)
        {
            maxSum = sum;
            
            save.clear();
            save.push_back(way);
        }
        else if(maxSum == sum)
        {
            save.push_back(way);
        }
    }
    
    else
    {
        for(int i = 0; i < 2; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(0 <= xx && xx < n && 0 <= yy && yy <= xx)
            {
                sum += arr[xx][yy];
                way.push_back(arr[xx][yy]);
                
                Try(xx,yy);
                
                sum -= arr[xx][yy];
                way.pop_back();
            }
        }
    }
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cin >> arr[i][j];
    }
    
    sum = arr[0][0];
    way.push_back(arr[0][0]);
    
    Try(0,0);
    
    cout << maxSum << "\n";
    
    for(auto x : save)
    {
        for(auto y : x)
            cout << y << " ";
        cout << "\n";
    }
    
    return 0;
}
