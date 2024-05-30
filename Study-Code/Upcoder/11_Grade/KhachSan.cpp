#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    
    int res = 0;
    if(n < 1 || n > 7 || m < 1 || m > 7)
    {
        cout << "NHAP SAI";
    }
    else 
    {
        if(n == m)
        {
            res = 0;
        }
        else if(n == 1)
        {
            res = 400000 + (m - n - 1) * 300000;
        }
        else if(n > m && m == 1)
        {
            res = (7 - n + m) * 300000;
        }
        else if(n > m)
        {
            res = 400000 + (6 - n + m) * 300000;
        }
        else
        {
            res = (m - n) * 300000;
        }
        
        cout << res;
    }
    return 0;
}
