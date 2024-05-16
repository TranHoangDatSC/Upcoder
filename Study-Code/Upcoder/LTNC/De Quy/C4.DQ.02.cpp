#include <iostream>
#include <cmath>
//1. Sử dụng hàm đệ quy
using namespace std;

int tong(int n)
{
    if(n == 0) return 0;
    else return pow(n,2) + tong(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << tong(n);
    return 0;
}
