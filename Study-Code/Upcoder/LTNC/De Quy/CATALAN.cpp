#include <iostream>
using namespace std;

unsigned long int deQuy(int n)
{
    if(n <= 1)
        return 1;
        
    unsigned long int res = 0;
    for(int i = 0; i < n; i++)
    {
        res += deQuy(i) * deQuy(n - i - 1);
    }
    return res;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << deQuy(n) << "\n";
    }
    return 0;
}
