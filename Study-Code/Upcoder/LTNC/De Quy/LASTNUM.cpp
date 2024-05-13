#include <iostream>
#include <string>
using namespace std;

int tongCS(int n)
{
    if(n < 10)
        return n;
    return  n % 10 + tongCS(n / 10);
}
int last(int n)
{
    while(n > 10)
    {
        n = tongCS(n);
    }
    return n;
}
int main()
{
    int n;
    cin >> n;
    cout << last(n);
    return 0;
}
