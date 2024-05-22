#include <iostream>
using namespace std;

int binary_search(int arr[],int n,int x)
{
    int left = 0, right = n - 1;
    
    while(left <= right)
    {
        int m = (left + right) / 2;
        
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
    int n, x;
    cin >> n >> x;
    
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    if(binary_search(arr,n,x) != -1)
    {
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == x) cout << i << " ";
        }
    }
    
    else cout << -1;
    
    return 0;
}
