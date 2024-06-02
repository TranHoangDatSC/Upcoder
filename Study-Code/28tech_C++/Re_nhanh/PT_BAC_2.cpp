#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a == 0)
    {
        if(b == 0 && c == 0)
        {
            cout << "Vo So Nghiem";
        }
        else if(b == 0 && c != 0)
        {
            cout << "Vo Nghiem";
        }
        else if(b != 0)
        {
            float res = - c/b;
            cout << setprecision(2) << fixed << (double)- c/b;
        }
    }
    
    else 
    {
        int delta = b*b - 4*a*c;
        
        if(delta < 0)
        {
            cout << "Vo Nghiem";
        }
        else if(delta == 0)
        {
            float res = -b/(2*a);
            cout << setprecision(2) << fixed << (double)-b/(2*a);
        }
        else
        {
            float x1 = (-b + sqrt(delta))/(2*a);
            float x2 = (-b - sqrt(delta))/(2*a);
            
            cout << setprecision(2) << fixed << x1 << " " << x2;
        }
    }
    return 0;
}
