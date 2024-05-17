#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool soCP(int n)
{
    return (int) sqrt(n) == sqrt(n);
}

int main()
{
    int n,k;
    cin >> n >> k;
    
    int *arr = new int[n];
    for(int i = 0 ; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    cout << count_if(arr,arr + n,soCP) << "\n";
    
    if(find(arr, arr + n, k) != (arr + n))
        cout << "Yes\n";
    else cout << "No\n";
    
    for(int i = 0; i < n; i++)
    {
        if(!soCP(arr[i]))
            cout << arr[i] << " ";
    }
    return 0;
}
