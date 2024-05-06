#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int demChuSo(int n)
{
    if(n < 10)
        return 1;
    else 
        return 1 + demChuSo(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << demChuSo(n);
    return 0;
}
