#include <iostream>
#include <vector>
using namespace std;

int n, m; // n hàng và m cột

int arr[100][100]; // Ma trận chứa các giá trị của nấm
int res[100]; // Mảng lưu các loại nấm đã thu thập trên đường đi
bool visited[100][100]; // Ma trận đánh dấu các ô đã thăm
int cnt = 0; // Số lượng đường đi hợp lệ
int k = 0; // Biến đếm số lượng nấm đã thu thập

void Try(int x, int y) 
{
    if (x == n && y == m) 
    {
        // Nếu đến ô cuối cùng, kiểm tra xem đã thu thập ít nhất 2 loại nấm ăn được hay không
        int save = res[0];
        for (int i = 1; i < k; i++) 
        {
            if (res[i] != save && res[i] != 0) 
            {
                cnt++;
                break;
            }
        }
    } 
    else 
    {
        // Di chuyển xuống dưới
        if (x + 1 <= n && arr[x + 1][y] != -1 && !visited[x + 1][y]) 
        {
            res[k++] = arr[x + 1][y];
            visited[x + 1][y] = true;
            Try(x + 1, y);
            --k;
            visited[x + 1][y] = false;
        }
        // Di chuyển sang phải
        if (y + 1 <= m && arr[x][y + 1] != -1 && !visited[x][y + 1]) 
        {
            res[k++] = arr[x][y + 1];
            visited[x][y + 1] = true;
            Try(x, y + 1);
            --k;
            visited[x][y + 1] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            cin >> arr[i][j];
        }
    }
    
    visited[1][1] = true; // Đánh dấu ô bắt đầu là đã thăm
    Try(1, 1); // Bắt đầu tìm kiếm từ ô (1,1)
    
    cout << (cnt == 0 ? -1 : cnt); // In ra kết quả
    return 0;
}
