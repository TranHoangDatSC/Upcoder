#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a, b;
    double cosC;
    
    cin >> a >> b >> cosC;
    
    if(cosC == 180)
        cout << "KHONG PHAI TAM GIAC";
    
    else 
    {
        double c = sqrt(pow(a,2) + pow(b,2) - 2 * a * b * cos(cosC * M_PI / 180));
        
        cout <<  roundf(c * 10000) / 10000;
    }
    
    return 0;
}
