#include <iostream>
#include <cmath>
using namespace std;

int giaiThua(int n)
{
    if(n <= 1)
        return 1;
    else 
        return n * giaiThua(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << giaiThua(n);
    return 0;
}
