#include <iostream>
#include <stack>
#include <string>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int tong(int n)
{
    if(n == 1)
        return 1;
    else 
        return n + tong(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << tong(n);
    return 0;
}
