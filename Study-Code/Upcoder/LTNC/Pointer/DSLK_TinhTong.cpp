#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int *arr = new int[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int tong(0);
    
    for(int i = 0; i < n; i++)
    {
        tong += *(arr + i);
    }
    cout << tong;
    
    delete[] arr;
    return 0;
}
