#include <iostream>
using namespace std;

int DaoNguoc(int a, int kq = 0)
{
    if(a == 0) return kq;
    
    kq = kq * 10 + a % 10;
    a /= 10;
    
    return DaoNguoc(a,kq);
}

int main()
{
    int n; cin >> n; cout << DaoNguoc(n);
    return 0;
}
