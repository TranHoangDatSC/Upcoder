#include <iostream>
using namespace std;

template<class DataType>
class LinkedList;

template<class DataType>
class Node {
    friend LinkedList<DataType>;
    private:
        DataType data;
        Node<DataType>* pNext;
    public:
        Node(DataType value) : data(value), pNext(NULL) {}
        void Display() {
            cout << data << " ";
        }
};

template<class DataType>
class LinkedList {
    private:
        Node<DataType>* pHead;
        Node<DataType>* pTail;
        int iSize;
    public:
        LinkedList() : iSize(0), pHead(NULL), pTail(NULL) {}
        void AddTail(DataType value) {
            Node<DataType>* pAdd = new Node<DataType>(value);
            if(pHead == NULL) {
                pHead = pTail = pAdd;
            }
            else {
                pTail->pNext = pAdd;
                pTail = pAdd;
            }
            iSize++;
        }
        void Display() {
            if(pHead != NULL) {
                Node<DataType>* pPre = NULL;
                Node<DataType>* pCur = pHead;
                Node<DataType>* pNext = NULL;
                while(pCur != NULL) {
                    pNext = pCur->pNext;
                    pCur->pNext = pPre;
                    pPre = pCur;
                    pCur = pNext;
                }
                
                bool check = false;
                while(pPre != NULL) {
                    if(check) cout << " ";
                    cout << pPre->data;
                    pPre = pPre->pNext;
                    check = true;
                }
            }
        }
};

int main() {
    LinkedList<int> ll;
    int n;
    while(cin >> n) 
        ll.AddTail(n);
    
    ll.Display();
    return 0;
}
