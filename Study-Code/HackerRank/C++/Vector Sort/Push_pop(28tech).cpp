/*
- Thao tác 1: nhập số thao tác cần thực hiện
- Thao tác 2: nhập 1 thì thêm phần tử, nhập 2 thì bỏ phần tử khỏi cuối vector nếu vector k rỗng

Sample Input:
6
1 34
2 
2
1 31
1 46
2
Sample Output:
31
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,c,k;
    cin >> n;
    
    vector<int> vt;
    while(n--)
    {
        cin >> c;
        
        switch(c)
        {
            case 1:
            {
                cin >> k;
                vt.push_back(k);
                break;
            }
            case 2:
            {
                if(!vt.empty())
                    vt.pop_back();
                break;
            }
        }
    }
    
    for(auto x : vt)
    {
        cout << x << " ";
    }
    return 0;
}
