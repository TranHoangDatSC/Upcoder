#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else return gcd(b,a % b);
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b);
    return 0;
}
