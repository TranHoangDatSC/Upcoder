#include <iostream>
using namespace std;

int main()
{
    int n, s = 0;
    cin >> n;
    
    if(n == 0)
    {
        cout << 0;
        return 0;
    }
    if(n < 0)
    {
        n = -n;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            s += i;
    }
    cout << s;
    return 0;
}
