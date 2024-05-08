#include <iostream>
using namespace std;

long tongS(long n)
{
    if(n == 0)
        return 0;
    else
        return n * (n + 1) / 2 + tongS(n - 1);
}
long tongP(long n)
{
    if(n == 0) return 0;
        
    long product = 1;
    for(long i = 1; i <= n; i++)
    {
        product *= i;
    }
    return product + tongP(n - 1);
}
int main()
{
    long n;
    cin >> n;
    cout << "S(" << n << ") = " <<  tongS(n);
    cout << "\nP(" << n << " ) = " << tongP(n);
    return 0;
}
