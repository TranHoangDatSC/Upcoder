#include <iostream>
using namespace std;

void input(int arr[],int n);
void output(int arr[],int n);

void bubble_sort(int arr[], int n);
// Thuật toán sắp xếp nổi bọt, tr/hợp: Bé -> Lớn

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    input(arr,n);
    
    bubble_sort(arr,n);

    output(arr,n);
    
    return 0;
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
