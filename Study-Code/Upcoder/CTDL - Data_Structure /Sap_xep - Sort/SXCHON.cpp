#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void select_sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
       int min_idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    int n(0);
    int arr[100];
    
    while(cin >> arr[n])
        n++;
        
    select_sort(arr,n);
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
        
    return 0;
}
