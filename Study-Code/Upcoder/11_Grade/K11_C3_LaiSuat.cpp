#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n,m;
    cin >> n >> m;
    
    if(m < 0 || n < 0)
    {
        cout << 0;
        return 0;
    }
    double interest = n*0.05;
    double res = interest;
    
    while(m < 12)
    {
        interest *= 0.05;
        res += interest;
        m++;
    }
    
    cout << res + n;
    
    return 0;
}
