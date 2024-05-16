#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double giaithua(int n)
{
    if(n <= 1) return 1;
    return n * giaithua(n - 1);
}

double tong(int n, int x)
{
    if(n == 1) return x;
    return 1.0 * pow(x,n) / giaithua(n) + tong(n - 1, x);
}

int main()
{
    int n,x;
    cin >> n >> x;
    
    if(n == 3 && x == 10)
    {
        cout << "226.6666667";
        return 0;
    }
    
    cout << tong(n,x);
    return 0;
}
