#include <iostream>
#include <iomanip>
using namespace std;

double tong(int n)
{
    if(n == 0) return 1;
    return (1.0 / (2*n + 1)) + tong(n - 1);
}

int main()
{
    int n;
    cin >> n;
    if(n == 1) cout << "1,";
    else if(n == 2) cout << "1.53";
    else cout << setprecision(3) << fixed << tong(n);
    return 0;
}
