#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100;

int linear_search(int arr[],int size,int key) {
    int max = -10e6;
    for(int i = 0; i < size; i++) {
        if(arr[i] > max && arr[i] <= key)
            max = arr[i];
    }
    for(int i = 0; i < size; i++) {
        if(arr[i] == max && max != -10e6)
            return i;
    }
    return -1;
}

int array[MAX];
int size = 0;
int key;

void input() {
    cin >> key;
    while(cin >> array[size])
        size++;
}

void output() {
    cout << linear_search(array,size,key);
}

int main() {
    input();
    output();
    return 0;
}
