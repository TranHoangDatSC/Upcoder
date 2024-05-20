#include <iostream>
#include <string>
using namespace std;

long long cntZero(long long n)
{
    long long d = 0;
    long long k = 5;
    
    while(k <= n)
    {
        d += n / k;
        k *= 5;
    }
    return d;
}

int main()
{
    long long n;
    cin >> n;
    cout << cntZero(n);
    return 0;
}
