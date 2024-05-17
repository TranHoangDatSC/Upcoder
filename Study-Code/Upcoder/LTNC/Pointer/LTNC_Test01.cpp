#include <iostream>
using namespace std;

int main()
{
    int n,m,cnt(0);
    cin >> m >> n;
    
    bool *arr = new bool[1000];
    
    for(int i = 0 ; i < 1000; i++)
    {
        arr[i] = false;
    }
    
    while(m--)
    {
        int tmp;
        cin >> tmp;
        arr[tmp] = true;
    }
    
    while(n--)
    {
        int tmp;
        cin >> tmp;
        if(!arr[tmp])
            cnt++, arr[tmp] = true; 
    }
    cout << cnt;
    return 0;
}
