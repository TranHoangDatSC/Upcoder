#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n);
// Thuật toán sắp xếp nổi bọt, tr/hợp: Bé -> Lớn

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    bubble_sort(arr,n);
    for(int x : arr)
    {
        cout << x << " ";
    }
    
    return 0;
}

void bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1]) // Đổi thành "<" nếu muốn xếp số lớn nhất trước
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
