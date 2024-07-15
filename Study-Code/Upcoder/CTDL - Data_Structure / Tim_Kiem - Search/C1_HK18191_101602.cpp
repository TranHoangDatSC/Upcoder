#include <iostream>
using namespace std;

void linear_search(int arr[],int n,int x) {
    int Max = x;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > Max) {
            Max = arr[i];
            break;
        }
    }
    
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] == x) {
            cout << "Y" << endl << i;
            return;
        }
        
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] == Max) {
            cout << "N" << endl << i;
            return;
        }
    }
    cout << "N" << endl << -1;
}

int main() {
    int n,x;
    cin >> n >> x;
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    linear_search(arr,n,x);
    
    return 0;
}
