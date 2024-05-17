#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

struct LinkedList
{
    Node *head;

    LinkedList() : head(nullptr) {}
    
    void push(int n)
    {
        Node *node = new Node(n);
        
        if(head == nullptr)
            head = node;
        else
        {
            Node *tmp = head;
            
            while(tmp->next != nullptr)
                tmp = tmp->next;
            tmp->next = node;
        }
    }
    
    void print()
    {
        Node *tmp = head;
        while(tmp != nullptr)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
    
    ~LinkedList() {}
};

int main()
{
    LinkedList list;
    int tmp;
    
    while(cin >> tmp && tmp != -1)
    {
        list.push(tmp);
    }
    cout << "DSLK ban dau: ";
    list.print();
    return 0;
}
