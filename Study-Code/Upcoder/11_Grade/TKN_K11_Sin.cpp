#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, x;
    cin >> a >> x;
    cout << (a + sin(x))/(sqrt(pow(a,2) + pow(x,2) + 1));
    return 0;
}
