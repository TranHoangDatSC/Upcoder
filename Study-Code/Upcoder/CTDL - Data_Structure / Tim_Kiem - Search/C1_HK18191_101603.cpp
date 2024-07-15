#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[],int n,int x) {
    int target = INT_MIN;
    int res = -1;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] == x)
            return i;
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] >= target && arr[i] <= x)
            res = i, target = arr[i];
    }
    return res;
}

int main() {
    int n,x;
    cin >> n >> x;
    int arr[n];
    
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
        
    int res = linear_search(arr,n,x);
    
    if(res == -1) cout << "N" << endl << -1;
    else cout << (arr[res] == x ? "Y\n" : "N\n") << res;
    
    return 0;
}
