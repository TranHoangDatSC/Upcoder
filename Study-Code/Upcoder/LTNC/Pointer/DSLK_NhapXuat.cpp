#include <iostream>
using namespace std;

struct Node {
    Node *next;
    int data;
    
    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};

struct LinkedList {
    Node *head;
    
    LinkedList() : head(nullptr) {}
    
    void add(int n) 
    {
        Node *node = new Node(n);
        
        if(head == nullptr) 
        {
            head = node;
        }
        
        else 
        {
            Node *tmp = head;
            while(tmp->next != nullptr) 
            {
                tmp = tmp->next;
            }
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
    int n, tmp; 
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        list.add(tmp);
    }
    
    list.print();
    
    return 0;
}
