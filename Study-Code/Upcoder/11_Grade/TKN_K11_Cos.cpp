#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    cin >> n;
    
    cout << (abs(2*n + 3) / cos(n)) + sqrt(2 + cos(n));
    return 0;
}
