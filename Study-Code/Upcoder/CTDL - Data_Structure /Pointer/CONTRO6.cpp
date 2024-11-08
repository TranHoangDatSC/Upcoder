#include <iostream>
using namespace std;

template<class DataType>
class LinkedList;

template<class DataType>
class Node {
    friend LinkedList<DataType>;
    DataType data;
    Node<DataType>* pNext;
    Node(DataType value) : data(value), pNext(NULL) {}
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

        if (pHead == NULL) {
            pHead = pTail = pAdd;
        } else {
            pTail->pNext = pAdd;
            pTail = pAdd;
        }
        iSize++;
    }

    int GetSize() {
        return iSize;
    }

    void Display() {
        if (GetSize() > 0) cout << GetSize() << endl;
        else {
            cout << -1;
        }
        Node<DataType>* pWalker = pHead;
        while (pWalker) {
            cout << pWalker->data;
            if (pWalker->pNext) cout << " ";
            pWalker = pWalker->pNext;
        }
        cout << endl;
    }

    void Check() {
        LinkedList<DataType> res;
        if (iSize < 3) {
            cout << -1;
            return;
        }

        Node<DataType>* ptr1 = pHead;
        Node<DataType>* ptr2 = ptr1->pNext;
        Node<DataType>* ptr3 = ptr2->pNext;
        int idx = 2;

        while (ptr3 != NULL) {
            if (ptr1->data * ptr3->data == ptr2->data) {
                res.AddTail(idx);
            }
            ptr1 = ptr1->pNext;
            ptr2 = ptr2->pNext;
            ptr3 = ptr3->pNext;
            idx++;
        }

        if (res.GetSize() == 0) {
            cout << -1;
        } else {
            res.Display();
        }
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList<int> list;

    while (n--) {
        int tmp;
        cin >> tmp;
        list.AddTail(tmp);
    }

    list.Check();
    return 0;
}




// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int n): data(n), next(nullptr) {}
// };

// struct Linkedlist {
//     Node* head;
//     Linkedlist(): head(nullptr) {}

//     void add(int n) {
//         Node* node = new Node(n);
//         Node* tmp = this->head;

//         if (tmp == nullptr)
//             this->head = node;
//         else {
//             while (tmp->next != nullptr) 
//                 tmp = tmp->next;
//             tmp->next = node;
//         }
//         return;
//     }

//     int size() {
//         int size = 0;
//         Node* tmp = this->head;
//         while (tmp != nullptr) 
//             size += 1,
//             tmp = tmp->next;
//         return size;
//     }

//     void print() {
//         if (this->size() > 0)
//             cout << this->size() << endl;
//         else {
//             cout << -1;
//             return;
//         }

//         Node* tmp = this->head;
//         while (tmp != nullptr) {
//             cout << tmp->data << " ";
//             tmp = tmp->next;
//         }
//         return;
//     }

//     void check() {
//         Linkedlist res;
//         Node* ptr1 = this->head;
//         int index = 2;

//         if (ptr1 == nullptr || ptr1->next == nullptr || ptr1->next->next ==nullptr) {
//             cout << -1;
//             return;
//         }

//         while (ptr1->next->next != nullptr) {
//             Node* ptr2 = ptr1->next->next;
//             Node* ptr3 = ptr1->next;

//             if (ptr1->data*ptr2->data == ptr3->data)
//                     res.add(index);

//             ptr1 = ptr1->next;
//             index += 1;
//         }
//         res.print();
//         return;
//     }

//     ~Linkedlist() {
//         Node* tmp = this->head;
//         Node* next;

//         while (tmp != nullptr) {
//             next = tmp->next;
//             delete tmp;
//             tmp = next;
//         }

//         this->head = nullptr;
//         return;
//     }
// };

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n; cin >> n;
//     Linkedlist list;

//     while (n--) {
//         int tmp; cin >> tmp;
//         list.add(tmp);
//     }

//     list.check();
//     return 0;
// }
