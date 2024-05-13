#include <iostream>
#include <string>
using namespace std;

int giaiThua(int n)
{
    if(n == 1)
        return 1;
    else return n * giaiThua(n - 1);
}
void hoanVi(int n, string str)
{
    if(str.size() == n)
        cout << str << "\n";
    else 
    {
        for(int i = 1; i <= n; i++)
        {
            string number = to_string(i);
            auto check = str.find(number);
            if(check != string::npos)
                continue;
            else 
                hoanVi(n,str + number);
        }
    }
}
int main()
{
    int n;
    string str;
    cin >> n;
    cout << giaiThua(n) << "\n";
    hoanVi(n,str);
    return 0;
}
