#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int luyThuaNhiPhan(int a, int b)
{
    if(b == 0)
        return 1;
    
    int x = luyThuaNhiPhan(a, b / 2);
    if(b % 2 == 1)
        return a * x * x;
    else    
        return x * x;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << luyThuaNhiPhan(a,b);
    return 0;
}
