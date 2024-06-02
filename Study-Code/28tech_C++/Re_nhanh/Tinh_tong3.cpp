#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double sum(long long n)
{
    if(n == 1) return (double)1/2;
    else return (double)1/(n * (n + 1)) + sum(n - 1);
}

int main()
{
    long long n;
    cin >> n;
    
    cout << sum(n);
    return 0;
}
