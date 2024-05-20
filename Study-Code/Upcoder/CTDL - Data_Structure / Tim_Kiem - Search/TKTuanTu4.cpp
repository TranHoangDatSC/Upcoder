#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int x)
{
    int res = -10e6;
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= x && arr[i] > res)
            res = arr[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == res && arr[i] != -10e6)
            return i;
    }
    return -1;
}

int main()
{
    int x;
    cin >> x;
    
    int n = 0;
    int arr[100];
    
    while(cin >> arr[n])
    {
        n++;
    }
    
    if(linear_search(arr,n,x) != -1)
    {
        int res = -10e6;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] <= x && arr[i] > res)
            {
                res = arr[i];
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != -10e6 && arr[i] == res)
                cout << i << " ";
        }
    }
    
    else cout << -1;
    return 0;
}
