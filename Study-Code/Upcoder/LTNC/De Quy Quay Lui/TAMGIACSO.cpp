#include <iostream>
using namespace std;

const int MAX_N = 100;

int arr[MAX_N][MAX_N];
int n;
int maxSum = 0;
int kq[MAX_N];
int luukq[MAX_N];
int sum;
int m = 1;
int dx[2] = {1,1};
int dy[2] = {0,1};

void Try(int x, int y)
{
    if(x == n - 1)
    {
        if(sum > maxSum)
        {
            maxSum = sum;
            for(int i = 0; i < n; ++i)
            {
                luukq[i] = kq[i];
            }
        }
    }
    else 
    {
        for(int i = 0; i < 2; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < n)
            {
                kq[m] = arr[xx][yy];
                ++m;
                sum += arr[xx][yy];
                Try(xx,yy);
                sum -= arr[xx][yy];
                --m;
                kq[m] = 0;
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
    kq[0] = arr[0][0];
    sum = arr[0][0];
    
    Try(0,0);
    
    for(int i = 0; i < n; i++)
    {
        cout << luukq[i] << " ";
    }
    cout << "\n" << maxSum;
    return 0;
}
