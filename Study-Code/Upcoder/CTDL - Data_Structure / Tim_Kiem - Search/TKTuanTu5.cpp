#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100;

int linear_search(int arr[],int size,int key,int maxDev) {
    int idx = -1;
    int minDev = maxDev + 1;
    
    for(int i = 0;i < size;i++) {
        if(arr[i] == key) {
            return i;
        }
        
        int dev = abs(arr[i] - key);
        if(dev <= maxDev) {
            if(dev < minDev || (dev == minDev && (idx == -1 || i < idx))) {
                minDev = dev;
                idx = i;
            }
        }
    }
    
    return idx;
}

int array[MAX];
int size;
int key;
int maxDev;

void input() {
    cin >> size >> key >> maxDev;
    
    for(int i = 0;i < size;i++) {
        cin >> array[i];
    }
}

void output() {
    cout << (linear_search(array,size,key,maxDev));
}

int main() {
    input();
    output();
    return 0;
}
