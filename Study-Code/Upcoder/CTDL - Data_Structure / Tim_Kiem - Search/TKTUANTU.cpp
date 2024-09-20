#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k,x;
    cin >> n >> k;
    
    vector<int> vt;
    while(n--)
    {
        cin >> x;
        vt.push_back(x);
    }
    
    int save = -1;
    for(int i = 0; i < vt.size(); i++)
    {
        if(vt[i] == k)
        {
            save = i;
            break;
        }
    }
    
    cout << save;
    
    return 0;
}

/*
#include <iostream>
using namespace std;

int linear_search(int arr[],int n,int x) {
    int res = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int n,x;
    int arr[100];
    
    cin >> n >> x;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << linear_search(arr,n,x);

    return 0;
}
*/
