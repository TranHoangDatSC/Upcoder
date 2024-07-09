#include <iostream>
using namespace std;

struct Set {
    int *element;
    int size;
    
    Set(int size) {
        this->size = 0;
        element = new int[size];
    }
    ~Set() {
        delete[] element;
    }
    
    bool check_linear_search(int target) {
        for(int i = 0; i < size; i++)
            if(element[i] == target) 
                return true;
        return false;
    }
    void insertion_sort() {
        int key;
        for(int i = 1; i < size; i++) {
            key = element[i];
            int j = i - 1;
            
            while(j >= 0 && element[j] > key) {
                element[j+1] = element[j];
                j = j - 1;
            }
            element[j+1] = key;
        }
    }
    bool insert(int n) {
        if(!check_linear_search(n)) {
            element[size++] = n;
            this->insertion_sort();
            return true;
        } else return false;
    }
    void print() {
        for(int i = 0; i < size; i++) {
            cout << element[i] << " ";
        }
    }
};

int main()
{
    int tmp, n;
    cin >> n;
    Set arr(n);
    
    while(cin >> tmp) 
        arr.insert(tmp);
        
    arr.print();
    return 0;
}
