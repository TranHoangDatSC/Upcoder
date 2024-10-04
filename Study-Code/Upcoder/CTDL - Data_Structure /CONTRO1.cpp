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
    
    int min() 
    {
        Node *tmp = head;
        int min = tmp->data;
        
        while(tmp != nullptr) 
        {
            if(tmp->data < min) 
            {
                min = tmp->data;
            }
            tmp = tmp->next;
        }
        return min;
    }
    
    int max() 
    {
        Node *tmp = head;
        int max = tmp->data;
        
        while(tmp != nullptr)
        {
            if(tmp->data > max)
            {
                max = tmp->data;
            }
            tmp = tmp->next;
        }
        return max;
    }
    
    void printMin() 
    {
        Node *tmp = head;
        int min = this->min();
        int index = 1;
        bool first = true; 
        
        while(tmp != nullptr) 
        {
            if(tmp->data == min)
            {
                if(!first) 
                {
                    cout << " ";
                }
                cout << index << " ";
                first = false;
            }
            tmp = tmp->next;
            index++;
        }
        cout << "\n";
    }
    
    void printMax() 
    {
        Node *tmp = head;
        int max = this->max();
        int index = 1;
        bool first = true;
        
        while(tmp != nullptr) 
        {
            if(tmp->data == max)
            {
                if(!first) 
                {
                    cout << " ";
                }
                cout << index;
                first = false;
            }
            tmp = tmp->next;
            index++;
        }
        cout << "\n";
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
    int tmp,n;
    
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> tmp;
        list.push(tmp);
    }
    
    cout << list.max() << "\n";
    list.printMax();
    cout << list.min() << "\n";
    list.printMin();
    
    return 0;
}
