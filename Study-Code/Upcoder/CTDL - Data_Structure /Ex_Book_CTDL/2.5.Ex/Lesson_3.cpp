#include <iostream>
using namespace std;

int binary_search(int arr[],int n,int target) {
    int cnt = 0; 
    int left = 0, right = n - 1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(arr[mid] == target)
            return cnt;
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        
        cnt++;
    }
    return -1;
} 

int main() {
    int n;
    cin >> n;
    int arr[n], target;
    cin >> target;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int res = binary_search(arr,n,target);
    
    cout << res;
    
    return 0;
}
