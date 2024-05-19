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
