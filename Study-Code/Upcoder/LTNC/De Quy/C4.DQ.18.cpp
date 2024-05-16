#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double tong(int n)
{
    if(n == 1) return sqrt(n);
    return sqrt(n + tong(n - 1)); 
}

int main()
{
    int n;
    cin >> n;
    cout << roundf(tong(n) * 1000) / 1000;
    return 0;
}
