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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    cin >> n;
    
    vector<int> vt(n);
    for(int &x : vt)
    {
        cin >> x;
    }
    
    cin >> m;
    
    sort(vt.begin(),vt.end(),[](int a, int b)
    {
        int a_mod = a % 3;
        int b_mod = b % 3;
        
        if(a_mod == 0)
            a_mod = 3;
        if(b_mod == 0)
            b_mod = 3;
            
        if(a_mod != b_mod) 
            return a < b;
    });
    
    if(m >= n)
        cout << "Khong Tim Thay";
    else 
        cout << vt[m];
    
    return 0;
}

*/
