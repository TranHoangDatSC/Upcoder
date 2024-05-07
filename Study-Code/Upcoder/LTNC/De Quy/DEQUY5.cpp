#include <iostream>
#include <cmath>
using namespace std;

double giaiThua(double n)
{
    if(n <= 1)
        return 1;
    else 
        return n * giaiThua(n - 1);
}

double tongHai(double n, double x)
{
    if(n == 0)
        return 1 + x;
    else 
        return (pow(x, 2 * n + 1) / giaiThua(2 * n + 1)) + tongHai(n - 1,x);
}

int main()
{
    double n,x;
    cin >> n >> x;
    double sum = tongHai(n,x);
    sum = roundf(sum * 1000) / 1000;
    cout << sum;
    return 0;
}
