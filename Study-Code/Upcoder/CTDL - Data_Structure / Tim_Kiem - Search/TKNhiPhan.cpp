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
