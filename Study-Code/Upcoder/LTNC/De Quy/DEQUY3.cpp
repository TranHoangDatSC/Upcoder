#include <iostream>
#include <string>
using namespace std;

void hoanVi(int n, int k, string str)
{
    if(str.size() == n)
        cout << str << "\n";
    else 
    {
        for(int i = 1; i <= k; i++)
        {
            string number = to_string(i);
            auto check = str.find(number);
            if(check != string::npos)
                continue;
            else 
                hoanVi(n,k,str + number);
        }
    }
}

int main()
{
    int n,k;
    string str;
    cin >> n >> k;
    hoanVi(n,k,str);
    return 0;
}
