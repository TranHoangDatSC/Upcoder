#include <iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;
    
    if(n < 0 )
        cout << "NHAP SAI";
    else 
    {
        if(n - (int)n >= 0.5) n = (int)n + 1;
        else n = (int)n;
        
        if(n < 2)
            cout << n*3000;
        else if(n > 1 && n <= 10)
            cout << 3000 + (n - 1) * 2000;
        else if(n > 10)
            cout << 3000 + 9 * 2000 + (n - 10) * 1500;
    }
    return 0;
}
