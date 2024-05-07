#include <iostream>
#include <cmath>
using namespace std;

int Cnk(int n,int k)
{
    if(k == 0 || k == n)
        return 1;
    else 
        return Cnk(n - 1, k) + Cnk(n - 1, k - 1);
}

int main()
{
    int n,k;
    cin >> n >> k;
    cout << Cnk(n,k);
    return 0;
}
