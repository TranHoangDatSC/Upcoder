#include <iostream>
#include <cmath>
using namespace std;

float giaiThua(float n)
{
    if(n <= 1)
        return 1;
    else 
        return n * giaiThua(n - 1);
}

float tongBa(float n, float x)
{
    if(n == 0)
        return x;
    else
        return pow(-1,n) * pow(x, 2 * n + 1) / giaiThua(2 * n + 1) + tongBa(n - 1,x);
}

int main()
{
    float n,x;
    cin >> n >> x;
    
    float sum = tongBa(n,x);
    
    sum = roundf(sum * 1000) / 1000;
    cout << sum;
    
    return 0;
}
