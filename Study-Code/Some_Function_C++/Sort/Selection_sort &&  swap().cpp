#include <iostream>
using namespace std;

void swap_num(int &a,int &b);
void selection_sort(int arr[], int n);
// Sắp xếp lựa chọn && swap()

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selection_sort(arr,n);
    
    for(int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}

void swap_num(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selection_sort(int arr[], int n)
{
    int min_idx;
    for(int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_idx]) // Có thể thay đổi thành ">" nếu muốn ngược lại
                min_idx = j;
        }
        swap_num(arr[min_idx],arr[i]);
    }
}
