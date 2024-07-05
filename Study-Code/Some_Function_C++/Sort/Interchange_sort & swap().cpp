#include <iostream>
using namespace std;

void swap_num(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Interchange_sort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++)
            if(arr[i] > arr[j])
                swap_num(arr[i],arr[j]);
}

int main()
{
    int arr[100], size = 0;
    while(cin >> arr[size])
        size++;
        
    selection_sort(arr,size);
    
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    
    return 0;
}

/* 
Input: 3 4 5 2 1
Output: 1 2 3 4 5

*/
