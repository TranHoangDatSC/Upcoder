#include <iostream>
#include <cmath>
using namespace std;

int tong(int n, int x)
{
    if(n == 0) return 0;
    else return pow(x,n) + tong(n - 1,x);
}

int main()
{
    int n,x;
    cin >> n >> x;
    cout << tong(n,x);
    return 0;
}
