#include <iostream>
#include <map>
//#include <stack>
using namespace std;

struct Stack
{
    char data[100];
    int index;
    
    void init()
    {
        this->index = -1;
    }
    bool empty()
    {
        return this->index == -1;
    }
    bool full()
    {
        return this->index == 99;
    }
    void push(char c)
    {
        if(!this->full())
            this->data[++this->index] = c;
    }
    char top()
    {
        if(!this->empty())
            return this->data[this->index];
            
        return -1;
    }
    void pop()
    {
        if(!this->empty())
        {
            --this->index;
        }
    }
};

int main()
{
    map<char, int> mp = {{'*','2'}, {'/','2'},{'+','1'},{'-','1'}};
    //stack<char> st;
    Stack st;
    st.init();
    
    char tmp;
    while(cin >> tmp)
    {
        if(tmp >= '0' && tmp <= '9')
            cout << tmp << " ";
        else if(st.empty() || tmp == '(')
            st.push(tmp);
        else if(tmp == ')')
        {
            while(st.top() != '(')
            {
                cout << st.top() << " ";
                st.pop();
            }
            st.pop();
        }
        else if(mp[tmp] <= mp[st.top()])
        {
            cout << st.top() << " ";
            st.pop();
            st.push(tmp);
        }
        else    
            st.push(tmp);
    }
    
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
