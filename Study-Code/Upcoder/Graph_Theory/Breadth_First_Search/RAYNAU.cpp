#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

// Hàm BFS để tìm vùng có rầy
vector<pii> bfs(vector<vector<int>>& grid, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();
    vector<pii> region;
    queue<pii> q;
    q.push({x, y});
    grid[x][y] = 0;  // Đánh dấu ô đã được duyệt

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        region.push_back(cur);

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                q.push({nx, ny});
                grid[nx][ny] = 0;  // Đánh dấu ô đã được duyệt
            }
        }
    }

    return region;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int total_area = 0;
    vector<vector<pii>> regions;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                vector<pii> region = bfs(grid, i, j);
                total_area += region.size();
                regions.push_back(region);
            }
        }
    }

    // In kết quả
    cout << total_area << endl;
    for (const auto& region : regions) {
        cout << region.size();
         for (int i = 0; i < region.size(); ++i) {
            cout << " [" << region[i].first + 1 << "," << region[i].second + 1 << "]";
            if (i != region.size() - 1) {
                cout << " , ";
            }
        }
        cout << endl;
    }

    return 0;
}
