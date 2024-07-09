#include <iostream>
using namespace std;

int binary_search(int arr[],int n,int target) 
{
    int left = 0;
    int right = n - 1;
    while(left<=right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] < target)
            left = mid + 1;
        else if(arr[mid] == target)
            return mid;
        else 
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n, target; 
    cin >> n >> target;
    int arr[n];
    
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    
    int res = binary_search(arr,n,target);
    cout << res;

    return 0;
}
