#include <iostream>
using namespace std;

int main()
{
    int a = 500;
    int b = 200;
    
    int tong = a + b;
    int hieu = a - b;
    int tich = a * b;
    double thuong = (double)a / (double)b; // 1 trong 2 cung duoc
    double du = a % b;
    
    cout << tong << endl;
    cout << hieu << endl;
    cout << tich << endl;
    cout << thuong << endl;
    cout << du;
    
    return 0;
}
