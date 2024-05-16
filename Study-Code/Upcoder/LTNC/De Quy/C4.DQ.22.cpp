#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double tong(int n, double x, int k)
{
    if(k == 0)
        return 0;
    else return sin(x * k) + cos(x * k) + tong(n,x,k - 1);
}

int main()
{
    int n;
    double x;
    cin >> n >> x;
    cout << fixed << setprecision(3) << tong(n,x * M_PI / 180,n);
    return 0;
}
