#include <iostream>
#include <cmath>
using namespace std;

bool CheckPrime(int n) {
    if(n < 2) return false;
    else {
        for(int i = 2; i <= sqrt((float)n); i++) 
            if(n % i == 0) return false;
    }
    return true;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void Interchange_Sort(int arr[],int size) {
    for(int i = 0;i < size - 1; i++) {
        if(CheckPrime(arr[i])) {
            for(int j = i + 1; j < size; j++) {
                if(arr[j] > arr[i] && CheckPrime(arr[j])) 
                    swap(arr[i],arr[j]);
            }
        }
    }
}

// void Insertion_Sort(int arr[],int size) {
//     int pos,i;
//     int x;
//     for(int i = 1; i < size; i++) {
//         x = arr[i];
//         if(CheckPrime(x)) {
//             for(pos = i; ((pos > 0) && 
//             (CheckPrime(arr[pos - 1])) && (arr[pos - 1] > x)); pos--) {
//                 arr[pos] = arr[pos - 1];
//             }
//             arr[pos] = x;
//         }
//     }
// }

int array[100];
int size;

void input() {
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }
}
void output() {
    Interchange_Sort(array,size);
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    input();
    output();
}
