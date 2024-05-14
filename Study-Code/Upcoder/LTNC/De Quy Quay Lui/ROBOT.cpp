#include <iostream>
using namespace std;

int n, arr[100][100];
int dx[] = {0,1};
int dy[] = {1,0};
string tmp, res = "";

int coSo2_10(string binary) // nhiPhan = binary
{
    int decimal = 0;
    int base = 1;
    
    int size = binary.size();
    for(int i = size - 1; i >= 0; i--)
    {
        if(binary[i] == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}

void Try(int i, int j)
{
    if(i == n-1 && j == n-1)
    {
        res = ((res > tmp) ? res : tmp);
    }
    
    for(int x = 0; x < 2; x++)
    {
        int u = i + dx[x];
        int v = j + dy[x];
        
        if(u >= 0 && u < n && v >= 0 && v < n)
        {
            tmp += arr[u][v] + '0';
            Try(u,v);
            tmp.pop_back();
        }
    }
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    tmp += (arr[0][0] + '0');
    Try(0,0);
    cout << coSo2_10(res);
    return 0;
}
