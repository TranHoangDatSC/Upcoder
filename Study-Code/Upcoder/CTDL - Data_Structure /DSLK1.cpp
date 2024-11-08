#include <iostream>
using namespace std;

template<class DataType>
struct Node {
    DataType data;
    Node<DataType>* pNext;
    Node(DataType value) : data(value), pNext(nullptr) {}
};

template<class DataType>
class LinkedList {
        Node<DataType>* pHead;
        Node<DataType>* pTail;
    public:
        LinkedList() : pHead(nullptr), pTail(nullptr) {}
        
        void AddTail(DataType value) {
            Node<DataType>* newNode = new Node<DataType>(value);
            if (pHead == nullptr) {
                pHead = pTail = newNode;
            } else {
                pTail->pNext = newNode;
                pTail = newNode;
            }
        }
        
        void Solve() {
            if (!pHead) return;
            
            Node<DataType>* pre = pHead;
            Node<DataType>* cur = pHead->pNext;

            while (cur) {
                if (pre->data >= cur->data) {  
                    pre->pNext = cur->pNext;
                    delete cur;
                    cur = pre->pNext;
                } else {
                    pre = cur;
                    cur = cur->pNext;
                }
            }
        }

        void Display() {
            Node<DataType>* pWalker = pHead;
            while (pWalker) {
                cout << pWalker->data;
                if (pWalker->pNext) cout << " ";
                pWalker = pWalker->pNext;
            }
            cout << endl;
        }

        ~LinkedList() {
            while (pHead) {
                Node<DataType>* temp = pHead;
                pHead = pHead->pNext;
                delete temp;
            }
        }
};

int main() {
    LinkedList<char> list;
    char c;

    while (cin >> c) {
        list.AddTail(c);
    }

    list.Solve(); 
    list.Display(); 

    return 0;
}
