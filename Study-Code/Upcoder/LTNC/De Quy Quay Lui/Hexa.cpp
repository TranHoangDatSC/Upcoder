#include <iostream>
#include <string>
using namespace std;

const string coSo = "0123456789ABCDEF";
string coSo16(long n)
{
    if(n == 0)
        return "";
    return coSo16(n / 16) + coSo[n % 16];
}

int main()
{
    long n;
    cin >> n;
    string res = coSo16(n);
    if(res == "")
        res = "0";
    cout << res;
    return 0;
}
