#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int c;
    cin >> c;
    double f = (c * (double)9/5) + 32;
    cout << setprecision(2) << fixed << f;
    
    return 0;
}
