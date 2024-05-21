#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    cin >> n;
    double res = sqrt(n + sqrt(n + sqrt(n)));
    cout << res;
    return 0;
}
