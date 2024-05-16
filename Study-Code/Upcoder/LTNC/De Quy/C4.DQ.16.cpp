#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double giaithua(int n)
{
    if(n <= 1) return 1;
    return n * giaithua(n - 1);
}

double tong(int n, int x)
{
    if(n == 0) return 1;
    return (pow(x,n * 2) / (giaithua(n*2))) + tong(n-1,x);
}

int main()
{
    int n,x;
    cin >> n >> x;
    cout << setprecision(3) << fixed <<tong(n,x);
    return 0;
}
