#include <iostream>
#include <vector> 
using namespace std;

int binary_search(int arr[], int n, int x)
{
    int lef = 0, rig = n - 1;
    
    while(lef <= rig)
    {
        int m = (rig + lef) / 2;
        
        if(arr[m] == x)
        {
            return m; // complete to search
        }
        else if(arr[m] < x)
        {
            lef = m + 1; // find on right
        }
        else
        {
            rig = m - 1; // find on left
        }
    }
    return -1; // lef > rig
}

int main()
{
    int n, x;
    cin >> n >> x;
    
    int arr[n];
    int cnt = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int res = binary_search(arr,n,x);
    cout << res;
    
    return 0;
}
/*
#include <iostream>
using namespace std;

int binary_search_recursive(int arr[], int lef, int rig, int x)
{
    if (lef <= rig)
    {
        int m = lef + (rig - lef) / 2; // Avoid potential overflow
        
        // Check if x is present at mid
        if (arr[m] == x)
        {
            return m;
        }
        // If x is greater, search in the right half
        else if (arr[m] < x)
        {
            return binary_search_recursive(arr, m + 1, rig, x);
        }
        // If x is smaller, search in the left half
        else
        {
            return binary_search_recursive(arr, lef, m - 1, x);
        }
    }
    
    return -1; // Element not found
}

int main()
{
    int n, x;
    cin >> n >> x;
    
    int arr[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    // Call the recursive binary search function
    int res = binary_search_recursive(arr, 0, n - 1, x);
    cout << res;
    
    return 0;
}

*/
