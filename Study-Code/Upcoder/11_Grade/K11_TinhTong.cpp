#include <iostream>
using namespace std;

int tong(int n)
{
    if(n == 1)  return 1;
    return n + tong(n - 1);
}

int main()
{
    int n;
    cin >> n;
    
    if(n < 0)
        cout << "NHAP SAI";
    else if(n == 0)
        cout << 0;
    else 
        cout << tong(n);
        
    return 0;
}
