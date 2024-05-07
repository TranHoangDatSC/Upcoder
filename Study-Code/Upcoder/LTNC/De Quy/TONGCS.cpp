#include <iostream>
#include <string>

using namespace std;
int solve(int n)
{
    if(n < 10)
        return n;
    else 
        return n % 10 + solve(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
