#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Stack
{
    int data[100];
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
    void push(int c)
    {
        if(!this->full())
            this->data[++this->index] = c;
    }
    int top()
    {
        if(!this->empty())
            return this->data[this->index];
            
        return -1;
    }
    void pop()
    {
        if(!this->empty())
            --this->index;
    }
};

int main()
{
    string str;
    getline(cin,str);
    stringstream ss(str);
    
    string tmp;
    Stack st;
    st.init();
    
    while(ss >> tmp)
    {
        if(tmp != "*" && tmp != "+" && tmp != "-")
            st.push(stoi(tmp));
            
        else 
        {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            
            if(tmp == "+")
                st.push(first + second);
            else if(tmp == "-")
                st.push(first - second);
            else if(tmp == "*")
                st.push(first * second);
        }
    }
    cout << st.top();
    
    return 0;
}
