#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int q, n, k;
    stack<int> st;
    
    cin >> q;
    
    while(q--)
    {
        cin >> n;
        
        switch(n)
        {
            case 1:
            {
                cin >> k;
                st.push(k);
                break;
            }
            case 2:
            {
                st.pop();
                break;
            }
            case 3:
            {
                int tmp = st.top();
                st.pop();
                cout << st.top() << "\n";
                st.push(tmp);
                break;
            }
        }
    }
    return 0;
}
