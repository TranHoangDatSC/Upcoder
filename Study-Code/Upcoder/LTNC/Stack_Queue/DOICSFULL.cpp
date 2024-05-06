#include <iostream>
#include <stack>
#include <string>
using namespace std;

void chuyenCoSo(long soHe10, int heCoSoMoi)
{
    string coSo16 = "0123456789ABCDEF";
    stack<string> st;
    
    switch(heCoSoMoi)
    {
        case 0:
        {
            while(soHe10 > 0)
            {
                st.push(to_string(soHe10 % 2));
                soHe10 /= 2;
            }
            break;
        }
        case 1:
        {
            while(soHe10 > 0)
            {
                st.push(to_string(soHe10 % 8));
                soHe10 /= 8;
            }
            break;
        }
        case 2:
        {
            while(soHe10 > 0)
            {
                st.push(string(1, coSo16[soHe10 % 16]));
                soHe10 /= 16;
            }
            break;
        }
    }
    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

int main()
{
    long coSo;
    cin >> coSo;
    int heSo;
    cin >> heSo;
    
    chuyenCoSo(coSo,heSo);
    return 0;
}
