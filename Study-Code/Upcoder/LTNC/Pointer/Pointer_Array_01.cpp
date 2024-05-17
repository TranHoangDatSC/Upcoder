#include <iostream>
using namespace std;

bool check(int *arr, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        if(arr[i] != arr[n - i - 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n; 
    
    int *arr = new int[n];
    
    for(int i = 0 ; i < n; i++)
    {
        cin >> *(arr + i);
    }

    if(check(arr,n)) cout << "mang doi xung";
    else 
    {   
        cout << "mang khong doi xung";
        for(int i = 0 ; i < n/2; i++)
        {
            if(arr[i] != arr[n - i - 1])
                cout << arr[i] << " " << arr[n - i - 1] << "\n";
        }
    }
    return 0;
}
