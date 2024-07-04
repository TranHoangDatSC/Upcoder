#include <iostream>
using namespace std;

void input(int arr[], int n);
void output(int arr[], int n);

void insertion_sort(int arr[], int n);
// Sắp xếp chèn

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    input(arr,n);
    
    insertion_sort(arr,n);
    
    output(arr,n);
    
    return 0;
}

void input(int arr[], int n)
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
void insertion_sort(int arr[], int n)
{
    int key;
    for(int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key) // Có thể đổi "<" nếu muốn lớn -> bé
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}
