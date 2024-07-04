#include <iostream>
using namespace std;

void swap_num(int &a,int &b);
void input(int arr[], int n);
void print_res(int arr[], int n);

void selection_sort(int arr[], int n);
// Sắp xếp lựa chọn && swap()

int main()
{
    int n;
    cin >> n;
    int arr[n];
    
    input(arr,n);
    
    selection_sort(arr,n);
    
    print_res(arr,n);
    
    return 0;
}

void swap_num(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void input(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void print_res(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
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
