#include <bits/stdc++.h>
using namespace std;

int n, arr[100][100];
int dx[] = {0,1};
int dy[] = {1,0};
string tmp,res = "";

int DoiCS10(string bin);
void Try(int x,int y);

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    tmp += (arr[0][0] + '0');
    Try(0,0);
    cout << DoiCS10(res);
    
    return 0;
}

int DoiCS10(string bin)
{
    int n1=1,n0=0;
    for(int i = bin.size() - 1; i >= 0; i--)
    {
        if(bin[i] == '1')
            n0 += n1;
        n1 *= 2;
    }
    return n0;
}

void Try(int x, int y)
{
    if(x == n - 1 && y == n - 1) 
    {
        res = ((res > tmp) ? res : tmp);
    }
    
    for(int i = 0; i < 2; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if(xx >= 0 && xx < n && yy >= 0 && yy < n)
        {
            tmp += arr[xx][yy] + '0';
            Try(xx,yy);
            tmp.pop_back();
        }
    }
}
