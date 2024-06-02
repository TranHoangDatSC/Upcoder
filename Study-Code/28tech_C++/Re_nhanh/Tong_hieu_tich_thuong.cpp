#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int tong = a + b;
    int hieu = a - b;
    int tich = (long long)a * b;
    int thuong = (double)a / b;
    
    cout << tong << "\n" << hieu << "\n";
    cout << tich << "\n" << thuong;
    return 0;
}
