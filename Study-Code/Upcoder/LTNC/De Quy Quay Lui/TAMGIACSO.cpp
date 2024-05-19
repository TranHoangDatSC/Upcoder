#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1,1};
int dy[] = {0,1};

int n;
int arr[100][100];

int save[100];
int res[100];
int sum;
int maxSum = 0;

int m = 1;

void Try(int x, int y)
{
    if(x == n - 1)
    {
        if(sum > maxSum)
        {
            maxSum = sum;
            for(int i = 0; i < n; ++i)
            {
                save[i] = res[i];
            }
        }
    }
    else
    {
        for(int i = 0; i < 2; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx >= 0 && xx < n && yy >= 0 && yy < n)
            {
                res[m] = arr[xx][yy];
                ++m;
                sum += arr[xx][yy];
                Try(xx,yy);
                sum -= arr[xx][yy];
                --m;
                res[m] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i + 1; ++j)
        {
            cin >> arr[i][j];
        }
    }
    
    res[0] = arr[0][0];
    sum = arr[0][0];
    
    Try(0,0);
    
    for(int i = 0; i < n; ++i)
    {
        cout << save[i] << " ";
    }
    cout << "\n" << maxSum;
    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

int n;

int sum;
int arr[100][100];
int maxSum = 0;

int dx[] = {1,1};
int dy[] = {0,1};

vector<int> save, way;

void Try(int x, int y)
{
    if(x == n)
    {
        if(sum > maxSum)
        {
            maxSum = sum;
            save = way;
        }
    }
    
    else 
    {
        for(int i = 0; i < 2; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(1 <= xx && xx <= n && 1 <= yy & yy <= xx)
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
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    sum = arr[1][1];
    way.push_back(arr[1][1]);
    
    Try(1,1);
    
    for(int x : save)
    {
        cout << x << " ";
    }
    cout << "\n" << maxSum; 
    
    return 0;
}
*/
