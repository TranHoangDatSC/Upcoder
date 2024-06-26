#include <iostream>
#include <cmath>
using namespace std;

int linear_search(int arr[],int target,int n,int max_diff)
{
    int index = -1;
    int min_diff = max_diff + 1;
    for(int i = 0; i < n; i++)
    {
        int diff = abs(arr[i] - target);
        
        if(diff <= max_diff && diff < min_diff)
        {
            min_diff = diff;
            index = i;
        }
        
        if(arr[i] == target)
        {
            index = i;
            break;
        }
    }
    return index;
}

int main()
{
    int n, target, diff;
    cin >> n >> target >> diff;
    int arr[n];
    
    for(auto &x : arr)
        cin >> x;
        
    int res = linear_search(arr,target,n,diff);
    cout << res;
    
    return 0;
}
