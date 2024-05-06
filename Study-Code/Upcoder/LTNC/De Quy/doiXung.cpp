#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int doiXung(int arr[],int left, int right)
{
    if(left >= right)
        return 1; // vi khong doi xung
    if(arr[left] != arr[right])
        return 0;
    else
        return doiXung(arr, left + 1, right - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    
    for(int &x : arr)
    {
        cin >> x;
    }
    cout << (doiXung(arr,0,n-1) ? "YES" : "NO");
    return 0;
}
