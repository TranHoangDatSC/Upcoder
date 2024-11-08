#include <iostream>
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

void DoiCoSo(long soHe10,int soHeMoi) {
    string soHe16 = "0123456789ABCDEF";
    Stack<string> st;
    
    switch(soHeMoi) {
        case 0: {
            while(soHe10 > 0) {
                st.Push(to_string(soHe10 % 2));
                soHe10 /= 2;
            } break;
        }
        case 1: {
            while(soHe10 > 0) {
                st.Push(to_string(soHe10 % 8));
                soHe10 /= 8;
            } break;
        }
        case 2: {
            while(soHe10 > 0) {
                st.Push(string(1,soHe16[soHe10 % 16]));
                soHe10 /= 16;
            } break;
        }
    }
    while(!st.IsEmpty()) {
        cout << st.Peek();
        st.Pop();
    }
}

int main() {
    long soHe10;
    cin >> soHe10;
    
    int soHeMoi;
    cin >> soHeMoi;
    
    DoiCoSo(soHe10,soHeMoi);
    return 0;
}