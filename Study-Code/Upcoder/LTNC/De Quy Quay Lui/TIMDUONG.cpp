#include <iostream>
#include <cstring> // Thư viện cho hàm memset
#include <queue>   // Thư viện cho hàng đợi queue
#include <vector>  // Thư viện cho vector
using namespace std;

// Biến lưu số đỉnh, số cạnh, đỉnh xuất phát và đỉnh kết thúc
int soDinh, soCanh, dinhXuatPhat, dinhKetThuc;
vector<int> vt[1000]; // Danh sách kề của đồ thị
bool visited[1000];   // Mảng đánh dấu đỉnh đã được thăm
int cnt[1000];        // Mảng đếm số bước để đến từng đỉnh

// Hàm thực hiện BFS (Duyệt theo chiều rộng)
void Try(int _dinhXuatPhat)
{
    queue<int> q; // Hàng đợi để quản lý BFS
    q.push(_dinhXuatPhat); // Đưa đỉnh xuất phát vào hàng đợi
    visited[_dinhXuatPhat] = true; // Đánh dấu đỉnh xuất phát là đã thăm
    cnt[_dinhXuatPhat] = 0; // Khởi tạo số bước đi cho đỉnh xuất phát là 0
    
    // Tiếp tục duyệt BFS cho đến khi hàng đợi trống
    while(!q.empty())
    {
        int v = q.front(); // Lấy đỉnh ở đầu hàng đợi
        q.pop(); // Loại bỏ đỉnh ở đầu hàng đợi
        
        // Duyệt qua tất cả các đỉnh kề của đỉnh v
        for(int x : vt[v]) 
        {
            // Nếu đỉnh kề x chưa được thăm
            if(!visited[x])
            {
                q.push(x); // Đưa đỉnh x vào hàng đợi
                visited[x] = true; // Đánh dấu đỉnh x là đã thăm
                cnt[x] = cnt[v] + 1; // Tăng số bước để đến đỉnh x từ đỉnh v lên 1
            }
        }
    }
}

int main()
{
    // Nhập vào số đỉnh, số cạnh, đỉnh xuất phát và đỉnh kết thúc
    cin >> soDinh >> soCanh >> dinhXuatPhat >> dinhKetThuc;
    
    // Nhập các cạnh và xây dựng danh sách kề
    for(int i = 0; i < soCanh; i++)
    {
        int x, y;
        cin >> x >> y;
        vt[x].push_back(y); // Thêm đỉnh y vào danh sách kề của đỉnh x
        vt[y].push_back(x); // Thêm đỉnh x vào danh sách kề của đỉnh y
    }
    
    // Khởi tạo mảng visited và cnt
    memset(visited, false, sizeof(visited)); // Đánh dấu tất cả các đỉnh là chưa được thăm
    memset(cnt, -1, sizeof(cnt)); // Khởi tạo số bước đến tất cả các đỉnh là -1
    
    // Gọi hàm BFS bắt đầu từ đỉnh xuất phát
    Try(dinhXuatPhat);
    
    // In ra số bước để đến đỉnh kết thúc
    cout << cnt[dinhKetThuc];
    
    return 0;
}
