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
    Stack<long> st;
    long n;
    cin >> n;
    
    if(n == 0) {
        cout << "0";
        return 0;
    }
    while(n > 0) {
        st.Push(n % 2);
        n /= 2;
    }
    
    while(!st.IsEmpty()) {
        cout << st.Peek();
        st.Pop();
    }
    
    return 0;
}
