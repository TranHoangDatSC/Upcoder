#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    
    while(left <= right)
    {
        int m = (right + left) / 2;
        
        if(arr[m] == x)
            return m;
        else if(arr[m] < x)
            left = m + 1;
        else 
            right = m - 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    
    cin >> n >> k;
    
    int arr[n];
    for(auto &x : arr)
    {
        cin >> x;
    }
    
    if(binary_search(arr,n,k) != -1)
    {
        for(int i = 0; i < n; i++)
            if(arr[i] == k) cout << i << " ";
    }
    
    else cout << -1;
    
    return 0;
}
