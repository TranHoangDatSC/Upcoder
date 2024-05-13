#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double giaiThua(int n)
{
    if(n == 1)
        return 1;
    return n * giaiThua(n - 1);
}
double funcCos(double x, double n = 10)
{
    if(n == 0)
        return x;
    return (pow(-1, n) * (pow(x,2*n + 1) / giaiThua(2*n + 1))) + funcCos(x, n - 1); 
}
double funcSin(double x, double n = 10)
{
    if(n == 0)
        return 1;
    return (pow(-1, n) * (pow(x,2*n) / giaiThua(2*n))) + funcSin(x, n - 1); 
}
int main()
{
    double x; 
    cin >> x;
    
    cout << roundf(funcCos(x) * 100) / 100 << '\n';
    cout << roundf(funcSin(x) * 100) / 100;
    return 0;
}
