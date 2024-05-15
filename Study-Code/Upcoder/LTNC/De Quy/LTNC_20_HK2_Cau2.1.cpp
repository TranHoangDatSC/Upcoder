#include <iostream>
#include <cmath>
using namespace std;

double sum(int n)
{
    if(n == 1) return 1;
    return sqrt(n + sum(n - 1));
}

int main()
{
    int n;
    cin >> n;
    cout << roundf(sum(n) * 1000) / 1000;
    return 0;
}
