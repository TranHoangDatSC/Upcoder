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
