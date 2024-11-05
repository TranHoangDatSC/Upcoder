#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100;

int binary_search(int arr[],int size,int key) {
    int right = size - 1, left = 0;
    
    while(left <= right) {
        int mid = (left + right)/2;
        
        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            left = mid + 1;
        }
        else if(arr[mid] > key) {
            right = mid - 1;
        }
    }
    return -1;
}

int array[MAX];
int size, key;

void input() {
    cin >> size >> key;
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void output() {
    if(binary_search(array,size,key) != -1) {
        for(int i = 0; i < size; i++)
            if(array[i] == key) 
                cout << i << " ";
    }
    else cout << -1;
}

int main() {
    input();
    output();
    return 0;
}
