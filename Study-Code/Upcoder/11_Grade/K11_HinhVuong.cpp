#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    cin >> n;
    if(n < 0)
        cout << "NHAP SAI";
    else cout << sqrt(n);
    return 0;
}
