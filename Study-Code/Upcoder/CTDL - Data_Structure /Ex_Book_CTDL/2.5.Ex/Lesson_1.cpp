#include <iostream>
using namespace std;

void linear_search(int arr[], int &n, int target) {
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != target) {
            arr[idx++] = arr[i];
        }
    }
    n = idx; 
}

int main() {
    int n;
    cin >> n;
    int arr[n], target;
    cin >> target;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
        
    linear_search(arr, n, target);
        
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
// Tìm và xóa hết phần tử target trong mảng A có n phần tử.
