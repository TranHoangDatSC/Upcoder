#include <iostream>
using namespace std;

int giaithua(int n)
{
    if(n <= 1) return 1;
    else return giaithua(n - 1) * n;
}

int tong(int n)
{
    if(n == 0) return 0;
    return tong(n - 1) + n * giaithua(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << tong(n);
    return 0;
}
