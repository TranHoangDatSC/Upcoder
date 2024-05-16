#include <iostream>
using namespace std;

void chuyenCoSo(int n)
{
    if(n < 2)
        cout << n;
    else 
    {
        chuyenCoSo(n / 2);
        cout << n % 2;
    }
}

int main()
{
    int n;
    cin >> n;
    chuyenCoSo(n);
    return 0;
}
