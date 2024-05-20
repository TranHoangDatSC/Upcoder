#include <iostream>
using namespace std;

int linear_search(int arr[], int cnt, int x)
{
    int res = -10e6;
    
    for(int i = 0; i < cnt; i++)
    {
        if(arr[i] <= x && arr[i] > res)
        {
            res = arr[i];
        }
    }
    for(int i = 0; i < cnt; i++)
    {
        if(res == arr[i] && res != -10e6)
            return i;
    }
    return -1;
}

int main()
{
    int x;
    cin >> x;
    
    int cnt(0);
    int arr[100];
    
    while(cin >> arr[cnt])
    {
        cnt++;
    }
    
    cout << linear_search(arr,cnt,x);
    return 0;
}
