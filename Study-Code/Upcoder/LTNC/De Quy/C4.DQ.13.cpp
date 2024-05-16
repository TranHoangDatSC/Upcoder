#include <iostream> 
#include <cmath>
using namespace std;

long long tong(int n, int x, int i = 1)
{
    if(i > n) return 0;
    return pow(x,i*2) + tong(n,x,i+1);
}

int main()
{
    int n,x;
    cin >> n >> x;
    cout << tong(n,x);
    return 0;
}
