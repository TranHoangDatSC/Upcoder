#include <iostream>
using namespace std;

int Fibo(int n)
{
    if(n == 1 || n == 0)
        return 1;
    return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << Fibo(i) << " ";
    }
    return 0;
}
/*
#include <iostream>
using namespace std;

int Fibo(int n)
{
    if(n <= 1)
        return n;
    else 
        return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cout << Fibo(i) << " ";
    }
    return 0;
}
*/
