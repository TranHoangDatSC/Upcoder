#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);

int main() {
    int arr[100], n;
    int idx = 0;
    while (cin >> arr[idx]) idx++;
    
    merge_sort(arr, 0, idx - 1);
    
    for (int i = 0; i < idx; i++) 
        cout << arr[i] << " ";
    
    return 0;
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i];
        
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];
    
    i = 0; 
    j = 0; 
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}
