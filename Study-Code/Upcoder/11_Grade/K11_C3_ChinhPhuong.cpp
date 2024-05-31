#include <iostream>
#include <cmath>
using namespace std;

int check(int n)
{
    int k = sqrt(n);
    if(k*k == n)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << (check(n) ? "True" : "False");
    return 0;
}
