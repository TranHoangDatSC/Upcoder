#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    stack<int> st;
    
    cin >> str;
    
    for(int i = 0; i < str.size();i++)
    {
        if(str[i] == '(') 
            st.push(i+1);
        else
        {
            cout << st.top() << " " << i + 1 << "\n";
            st.pop();
        }
    }
    return 0;
}
