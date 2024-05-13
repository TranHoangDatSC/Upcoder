#include <iostream>
#include <algorithm>
using namespace std;

void hoanVi(int n, int k, string str)
{
    if(str.size() == k)
        cout << str << "\n";
    else 
    {
        for(int i = 1; i <= n; i++)
        {
            string number = to_string(i);
            hoanVi(n,k,str + number);
        }
    }
}
int main()
{
    int n,k;
    cin >> n >> k;
    string str = "";
    cout << pow(n,k) << "\n";
    hoanVi(n,k,str); 
    return 0;
}
