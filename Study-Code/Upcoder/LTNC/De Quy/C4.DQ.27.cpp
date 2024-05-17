#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long tongCS(long long n)
{
    if(n < 10)
        return n;
    else return n % 10 + tongCS(n / 10);
}

long long lastNum(long long n)
{
    while(n > 10)
    {
        n = tongCS(n);
    }
    return n;
}

int main()
{
    long long n;
    cin >> n;
    cout << lastNum(n);
    return 0;
}
