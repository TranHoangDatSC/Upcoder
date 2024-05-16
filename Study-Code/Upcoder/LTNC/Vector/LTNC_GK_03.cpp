#include <iostream> 
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int len = 2*n + 2;
    vector<int> vt(len);
    vt[1] = 1;
    
    for(int i = 2; i < len; i++)
    {
        if(i % 2 == 0)
            vt[i] = vt[i / 2] + i / 2;
        else
            vt[i] = (i / 2) * (i / 2) + vt[i / 2] * vt[i / 2 + 1];
    }
    cout << vt[n];
    return 0;
}
