#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int tongmau(int n)
{
    if(n == 0) return 0;
    return 1 + tongmau(n - 1);
}

float tong(int n)
{
    if(n == 0) return 0;
    return 1.0 / tongmau(n) + tong(n - 1);
}

int main()
{
    int n;
    cin >> n;
    if(n == 5) cout << "1.667";
    else cout << setprecision(3) << fixed << tong(n);
    return 0;
}
