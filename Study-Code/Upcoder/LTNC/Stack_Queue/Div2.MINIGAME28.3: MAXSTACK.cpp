#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int q, n ,k;
    stack<int> st, MAX;
    
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
                
                if(MAX.empty() || MAX.top() < k)
                    MAX.push(k);
                    
                else MAX.push(MAX.top());
                
                break;
            }
            case 2:
            {
                st.pop();
                MAX.pop();
                break;
            }
            case 3:
            {
                cout << MAX.top() << "\n";
                break;
            }
            
        }
    }
    return 0;
}
