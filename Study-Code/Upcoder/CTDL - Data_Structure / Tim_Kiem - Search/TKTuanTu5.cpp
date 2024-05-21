#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, x ,y;
    cin >> n >> x >> y;
    
    int arr[100];
    for(int i = 0 ; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int index = -1;
    int lech_min = y + 1;  // khoi tao min_deviation
    
    for(int i = 0 ; i < n; i++)
    {
        if(arr[i] == x)
        {
            cout << i;
            return 0;
        }
        
        int lech = abs(arr[i] - x);

        if(lech < lech_min && lech <= y)
        {
            lech_min = lech;
            index = i;
        }
    }
    
    cout << index;
    return 0;
}
