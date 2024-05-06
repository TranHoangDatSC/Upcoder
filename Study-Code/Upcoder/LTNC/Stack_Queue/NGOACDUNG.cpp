#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char x;
    stack<char> st;
    
    while(cin >> x)
    {
        if(st.empty())
        {
            st.push(x);
        }
        else 
        {
            if((st.top() == '(' && x == ')') || (st.top() == '{' && x == '}')
            || (st.top() == '[' && x == ']'))
                st.pop();
                
            else
            {
                st.push(x);
            }
        }
    }
    
    cout << (st.empty() ? "yes" : "no");
    return 0;
}
