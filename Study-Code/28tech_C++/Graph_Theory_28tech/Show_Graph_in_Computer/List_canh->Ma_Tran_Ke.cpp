/*
Cho đồ thị vô hướng G = <V,E> đc biểu diễn dưới dạng danh sách cạnh. 
Viết chương trình thục hiện chuyển đổi biểu diễn đồ thị dưới dạng ma trận kề.

Input: 
+ Dòng đầu chứa 2 số n,m là số đỉnh và số cạnh của đồ thị (1 <= n && <= 1000, 1 <= m && m <= n*(n-1)/2)
+ M dòng tiếp theo mỗi dòng là 2 số u,v biểu diễn cạnh u,v của đồ thị (1 <= u, v <=n). Các cạnh đc liệt kê theo thứ tự tăng dần của đỉnh.

Output:
+ In ra ma trận kề tương ứng của đồ thị

Mấu:
- Input:
5 9
1 2
1 3
1 4
2 3
2 4
2 5
3 4
3 5
4 5

- Output:
0 1 1 1 0
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
*/

#include <iostream>
using namespace std;

int n,m;
int arr[1001][1001];

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << arr[i][j];
        cout << endl;
    }
    return 0;
}
