#include <iostream>
using namespace std;

long Sum(long n)
{
    if(n == 1)  return 1;
    return n + Sum(n - 1);
}
long S(long n)
{
    long res = 0;
    for(int i = 1; i <= n; i++)
    {
        res += Sum(i);
    }
    return res;
}
long factorial(long n)
{
    if(n == 1) return 1;
    return n * factorial(n - 1);
}
long P(long n)
{
    long res = 0;
    for(int i = 1; i <= n; i++)
    {
        res += factorial(i);
    }
    return res;
}

int main()
{
    long n; 
    cin >> n;
    if(n <= 20)
    {
        cout << "S(" << n << ") = " << S(n) << "\n";
        cout << "P(" << n << ") = " << P(n);
    } 
    return 0;
}

/*
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
*/
