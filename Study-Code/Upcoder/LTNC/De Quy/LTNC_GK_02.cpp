#include <iostream>
using namespace std;

int deQuy(int n)
{
    if(n == 1)
        return 1;
    else if(n % 2 == 0)
    {
        int half_n = n / 2;
        return half_n + deQuy(half_n);
    }
    else
    {
        int half_n = n / 2;
        return half_n * half_n + deQuy(half_n) * deQuy(half_n + 1);
    }
}

int main() 
{
    int n;
    cin >> n;
    cout << deQuy(n);
    return 0;
}
