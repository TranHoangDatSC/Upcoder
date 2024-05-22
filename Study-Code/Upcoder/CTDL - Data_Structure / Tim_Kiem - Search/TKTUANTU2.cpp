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

/*
#include <iostream>
#include <cmath>
using namespace std;

int jump_search(int arr[], int size, int target)
{
    int block_size = (int)sqrt(size);
    int start = 0;
    int next = block_size;
    
    while(start < size && target > arr[next - 1])
    {
        start = next;
        next += block_size;
        
        if(next >= size)
            next = size;
    }
    
    for(int i = 0; i < size; i++)
        if(arr[i] == target)
            return i;
    
    return -1;    
}

int main()
{
    int n,x; 
    cin >> n >> x;
    
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    if(jump_search(arr,n,x) != -1)
    {
        for(int i = 0; i < n; i++)
            if(arr[i] == x)
                cout << i << " ";
    }
                
    else cout << -1;
    
    return 0;
}
*/
