#include <iostream>
using namespace std;

int giaiThua(int n)
{
    if(n == 0)
        return n != 1;
    else if(n > 0)
        return giaiThua(n - 1) * n;
}
int main()
{
    int n;
    cin >> n;
    cout << giaiThua(n);
    return 0;
}
