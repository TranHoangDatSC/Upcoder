#include <iostream>
#include <algorithm>
using namespace std;

void hoanVi(int n)
{
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        arr[i] = i + 1;
    }
    
    do 
    {
        bool valid = true;
        for(int i = 1; i < n; ++i)
        {
            if(abs(arr[i] - arr[i - 1]) == 1)
            {
                valid = false; 
                break;
            }
        }
        if(valid)
        {
            for(int i = 0; i < n; ++i)
            {
                cout << arr[i];
            }
            cout << '\n';
        }
    }
    while(next_permutation(arr, arr + n));
}

int main()
{
    int n;
    cin >> n;
    hoanVi(n);
    return 0;
}
