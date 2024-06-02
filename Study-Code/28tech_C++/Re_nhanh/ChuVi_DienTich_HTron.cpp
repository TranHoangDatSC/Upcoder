#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int r;
    cin >> r;
    
    double chuvi = 2 * M_PI * r;
    double dientich = M_PI * r * r;
    
    cout << setprecision(2) << fixed << chuvi << " " << dientich;
    
    return 0;
}
