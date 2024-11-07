#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template<class DataType>
class Stack {
    private:
        DataType *arr;
        int iTop;
        int iCapacity;
    public:
        Stack();
        Stack(int maxSize);
        
        bool IsEmpty();
        bool IsFull();
        
        void Push(DataType data);
        DataType Pop();
        DataType Peek();
        int GetSize();
};

template<class DataType>
Stack<DataType>::Stack() {
    iCapacity = MAX_SIZE;
    arr = new DataType [iCapacity];
    iTop = -1;
}
template<class DataType>
Stack<DataType>::Stack(int maxSize) {
    iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
    arr = new DataType [iCapacity];
    iTop = -1;
}
template<class DataType>
bool Stack<DataType>::IsEmpty() {
    return iTop == -1;
}
template<class DataType>
bool Stack<DataType>::IsFull() {
    return iTop == iCapacity - 1;
}
template<class DataType>
void Stack<DataType>::Push(DataType data) {
    if(IsFull()) {
        cout << "FULL";
    }
    else {
        arr[++iTop] = data;
    }
}
template<class DataType>
DataType Stack<DataType>::Pop() {
    if(IsEmpty()) {
        cout << "Empty";
    }
    DataType tmp = arr[iTop];
    iTop--;
    return tmp;
}
template<class DataType>
DataType Stack<DataType>::Peek() {
    if(IsEmpty()) cout << "Empty";
    return arr[iTop];
    
}

int main() {
    Stack<char> st;
    char c;
    int idx = 0;
    
    while(cin >> c) {
        if(st.IsEmpty()) {
            st.Push(c);
        }
        else {
            if((st.Peek() == '(' && c == ')') || (st.Peek() == '[' && c == ']') 
            || (st.Peek() == '{' && c == '}' ))
                st.Pop();
            else 
                st.Push(c);
        }
    }
    cout << (st.IsEmpty() ? "yes" : "no");
    return 0;
}
