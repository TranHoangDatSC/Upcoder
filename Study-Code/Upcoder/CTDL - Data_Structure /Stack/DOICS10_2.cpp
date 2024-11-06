#include <iostream>
#include <stack>
//#include <cstdlib>
using namespace std;

int main()
{
    stack<long> st;
    long n;
    cin >> n;
    
    int kq;
    
    if(n == 0)
    {
        cout << "0";
        return 0;    // exit(0);
    }
    while(n > 0)
    {
        st.push(n % 2);
        n /= 2;
    }
    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}
