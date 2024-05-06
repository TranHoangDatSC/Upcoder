#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll fibonacci(int n)
{
    if(n <= 1)
        return n;
    else 
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
