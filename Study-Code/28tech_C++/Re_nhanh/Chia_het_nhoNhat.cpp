#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    long long a,b;
    cin >> a >> b ;
    
    if(a % b == 0)
        cout << a;
    else
        cout << ((a + b - 1) / b) * b;
    return 0;
}
