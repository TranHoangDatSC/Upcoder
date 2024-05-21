#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    int k;
    vector<int> vt;
    
    while(n--)
    {
        cin >> k;
        vt.push_back(k);
    }
    
    int del, ra,rb;
    cin >> del;
    del -= 1; // Trừ để về index = 0 nếu vị trí là vt[0] <=> i - 1 = 0
    
    cin >> ra >> rb;
    ra -= 1;
    
    vt.erase(vt.begin() + del);
    vt.erase(vt.begin() + ra, vt.begin() + rb - 1);
    
    cout << vt.size() << "\n";
    for(auto x : vt)
        cout << x << " ";
    
    return 0;
}
/*
- Xuất ra dòng đầu tiên là số lượng phần tử
- Dòng thứ 2 là phần các phần tử
- Dòng thứ 3 là vị trí đầu tiên cần xóa
- Dòng thứ 4 là phạm vi xóa

- Output là số phần tử còn lại

Sample Input
6
1 4 6 2 8 9
2
2 4
Sample Output
3
1 8 9
*/
