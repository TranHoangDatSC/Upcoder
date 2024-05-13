#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void chuoiHoanVi(int n, int size, string str)
{
    if(size == 0)
        cout << str << '\n';
    else
    {
        for(int i = 1; i <= n; i++)
            chuoiHoanVi(n,size-1,str + to_string(i));
    }
}

int main()
{
    int n, size;
    cin >> n >> size;
    
    cout << pow(n,size) << '\n';
    string str = "";
    chuoiHoanVi(n,size,str);
    return 0;
}
