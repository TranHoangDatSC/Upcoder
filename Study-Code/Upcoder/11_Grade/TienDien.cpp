#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if(n >= 200)
        cout << "CAT DIEN";
    else if(n < 0)
        cout << "NHAP SAI";
    else if(n <= 50)
        cout << n*2500;
    else if(n > 50 && n <= 100)
        cout << 50 * 2500 + (n - 50) * 3000;
    else if(n > 100 && n <= 200)
        cout << 50 * 2500 + 50 * 3000 + (n - 100) * 5000;
        
    return 0;
}
