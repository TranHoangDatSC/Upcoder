// Tìm số lớn nhất trong dãy số nguyên

#include <iostream>
#include <cmath>
using namespace std;

int Max_Number(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    cout << Max_Number(arr,n);

    return 0;
}
