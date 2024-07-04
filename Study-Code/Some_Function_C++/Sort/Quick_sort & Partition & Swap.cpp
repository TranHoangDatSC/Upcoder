#include <iostream>
using namespace std;

/* Nhanh hơn Insertion, Selection, Bubble     */

void swap_num(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Thuật toán Phân Đoạn (Partition)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    
    while(true)
    {
        while(left <= right && arr[left] < pivot)
            left++;
            
        while(left <= right && arr[right] > pivot)
            right--;
        
        /* Nếu muốn từ lớn -> bé, đảo ngược dấu của hai hàm while */
        
        if(left >= right)
            break;
            
        swap_num(arr[left],arr[right]);
        
        left++;
        right--;
    }
    swap_num(arr[left],arr[high]);
    
    return left;
}

// Thuật toán xếp nhanh (Quick Sort)
void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr,low,high);
        
        quick_sort(arr,low,pi - 1);
        quick_sort(arr,pi + 1, high);
    }
}

void input(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void output(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    input(arr,n);
    
    quick_sort(arr,0,n-1);
    output(arr,n);
    
    return 0;
}
