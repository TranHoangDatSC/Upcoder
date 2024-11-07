#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

template<class DataType>
class Stack {
    private:
        DataType *arr;
        int iTop;
        int iCapacity;
    public:
        void init();
        void push(DataType data);
        DataType top();
        DataType pop();
        bool empty();
        bool full();
};

template<class DataType>
void Stack<DataType>::init() {
    iCapacity = MAX_SIZE;
    arr = new DataType [iCapacity];
    iTop = -1;
}

template<class DataType>
bool Stack<DataType>::empty() {
    return iTop == -1;
}
template<class DataType>
bool Stack<DataType>::full() {
    return iTop == iCapacity - 1;
}
template<class DataType>
void Stack<DataType>::push(DataType data) {
    if(full()) {
        cout << "FULL";
    }
    else {
        arr[++iTop] = data;
    }
}
template<class DataType>
DataType Stack<DataType>::pop() {
    if(empty()) {
        cout << "Empty";
    }
    DataType tmp = arr[iTop];
    iTop--;
    return tmp;
}
template<class DataType>
DataType Stack<DataType>::top() {
    if(empty()) cout << "Empty";
    return arr[iTop];
}

int main() {
    string str;
    getline(cin,str);
    stringstream ss(str);
    
    string tmp;
    Stack<int> st;
    st.init();
    
    while(ss >> tmp) {
        if(tmp != "*" && tmp != "+" && tmp != "-" && tmp != "/")
            st.push(stoi(tmp));
        else {
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
            else if(tmp == "/")
                st.push(first / second);
        }
    }
    cout << st.top();
    return 0;
}
