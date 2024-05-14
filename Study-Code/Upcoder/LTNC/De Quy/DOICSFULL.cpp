#include <iostream>
#include <string>
#include <stack>
using namespace std;

void coSo2(stack<string> st, int n)
{
    if(n == 0)
    {
        while(!st.empty())
        {
            cout << st.top();
            st.pop();
        }
    }
    else
    {
        st.push(to_string(n % 2));
        coSo2(st, n / 2);
    }
}
void coSo8(stack<string> st, int n)
{
    if(n == 0)
    {
        while(!st.empty())
        {
            cout << st.top();
            st.pop();
        }
    }
    else
    {
        st.push(to_string(n % 8));
        coSo8(st, n / 8);
    }
}
void coSo16(stack<string> st, int n)
{
    string cs16 = "0123456789ABCDEF";
    if(n == 0)
    {
        while(!st.empty())
        {
            cout << st.top();
            st.pop();
        }
    }
    else
    {
        st.push(string(1, cs16[n % 16]));
        coSo16(st, n / 16);
    }
}

void chuyenCoSo(int soHe10, int heCoSoMoi = 0)
{
    stack<string> st;
    switch(heCoSoMoi)
    {
        case 0:
            coSo2(st,soHe10);
            break;
        case 1:
            coSo8(st,soHe10);
            break;
        case 2:
            coSo16(st,soHe10);
            break;
    }
}
int main()
{
    long heSo10;
    cin >> heSo10;
    int heCoSoMoi;
    cin >> heCoSoMoi;
    
    chuyenCoSo(heSo10,heCoSoMoi);
    return 0;
}
