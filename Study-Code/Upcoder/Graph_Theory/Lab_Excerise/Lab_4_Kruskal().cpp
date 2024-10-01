#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

struct Graph {
    int vertices;
    vector<Edge> T;  // Danh sách các cạnh của cây khung
    vector<vector<int>> adj;  // Ma trận trọng số
    vector<vector<int>> save;  // Lưu ma trận gốc để in ra

    Graph() : vertices(0), adj() {}
};

void readGraph(Graph& g, string fn) {
    ifstream f(fn);

    if (f.is_open()) {
        f >> g.vertices;

        g.adj.resize(g.vertices, vector<int>(g.vertices, 0));
        g.save.resize(g.vertices, vector<int>(g.vertices, 0));

        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                f >> g.adj[i][j];
                g.save[i][j] = g.adj[i][j];
            }
        }
        f.close();
    }
    else {
        cout << "Khong mo duoc file input!";
    }
}

void Init_Arr_Edge(Graph& g, int& nEdge, vector<Edge>& listEdge) {
    listEdge.clear();
    for (int i = 0; i < g.vertices; i++) {
        for (int j = i + 1; j < g.vertices; j++) {
            if (g.adj[i][j] != 0) {
                listEdge.push_back({ i, j, g.adj[i][j] });
            }
        }
    }
    nEdge = listEdge.size();
}

void Sort_Edge(vector<Edge>& listEdge) {
    sort(listEdge.begin(), listEdge.end(), [](Edge a, Edge b) {
        return a.u < b.u;  // Sắp xếp theo trọng số
        });
}

bool HaveLoop(int u, int v, vector<int>& Acp) {
    return Acp[u] == Acp[v];  // Kiểm tra có vòng lặp hay không
}

void Union(int u, int v, vector<int>& Acp) {
    int oldLabel = Acp[v];
    int newLabel = Acp[u];
    for (int i = 0; i < Acp.size(); i++) {
        if (Acp[i] == oldLabel) {
            Acp[i] = newLabel;  // Gán nhãn mới
        }
    }
}

void Kruskal(Graph& g, int& nT, vector<Edge>& T) {
    int nEdge;
    vector<int> Acp(g.vertices);
    vector<Edge> listEdge;

    Init_Arr_Edge(g, nEdge, listEdge);
    Sort_Edge(listEdge);

    nT = 0;
    for (int i = 0; i < g.vertices; i++) {
        Acp[i] = i;  // Khởi tạo nhãn cho các đỉnh
    }
    int iMin = 0;

    while (nT < g.vertices - 1 && iMin < nEdge) {
        int u = listEdge[iMin].u;
        int v = listEdge[iMin].v;

        if (!HaveLoop(u, v, Acp)) {
            T.push_back(listEdge[iMin]);  // Thêm cạnh vào cây khung
            nT++;
            Union(u, v, Acp);  // Kết hợp hai nhãn
        }
        iMin++;
    }
}

int SumT(const vector<Edge>& e) {
    int totalW = 0;
    for (const auto& edge : e) {
        totalW += edge.w;  // Tính tổng trọng số
    }
    return totalW;
}

void edgeTree(const vector<Edge>& e, ostream& os) {
    for (int i = 0; i < e.size(); i++) {
        os << "(" << e[i].u << "," << e[i].v << ") : " << e[i].w;
        if (i != e.size() - 1) os << "; ";
    }
    os << "\n";
}

void printSpanningTree(Graph& g, string fn) {
    ofstream f(fn);
    if (f.is_open()) {
        int nT = 0;
        Kruskal(g, nT, g.T);

        f << "Do thi cay khung nho nhat co ma tran la:\n";
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                f << setw(4) << g.save[i][j];
            }
            f << "\n";
        }

        f << "Tong trong so cua do thi cay khung nho nhat la: " << SumT(g.T) << "\n";
        f << "Cac canh cua cay khung:\n";
        edgeTree(g.T, f);
        f.close();
    }
    else {
        cout << "Khong mo duoc file output!";
    }
}

int main() {
    Graph g;
    readGraph(g, "input.txt");
    printSpanningTree(g, "output.txt");
    return 0;
}

/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

struct Graph {
    int vertices;
    vector<Edge> T;
    vector<vector<int>> adj;
    vector<vector<int>> saveMatrix;

    Graph() : vertices(0), adj() {}
};

void readGraph(Graph& g, string fn) {
    ifstream f(fn);
    if (f.is_open()) {
        f >> g.vertices;
        g.adj.resize(g.vertices, vector<int>(g.vertices, 0));
        g.saveMatrix.resize(g.vertices, vector<int>(g.vertices, 0));
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                f >> g.adj[i][j];
                g.saveMatrix[i][j] = g.adj[i][j];
            }
        }
        f.close();
    }
    else {
        cout << "Khong mo duoc file input!" << endl;
    }
}

void Init_Arr_Edge(int& nEdge, vector<Edge>& listE, Graph g) {
    listE.clear();
    for (int i = 0; i < g.vertices; i++) {
        for (int j = i + 1; j < g.vertices; j++) {
            if (g.adj[i][j] != 0) {
                listE.push_back({ i, j, g.adj[i][j] });
            }
        }
    }
    nEdge = listE.size();
}

void Sort_Edge(vector<Edge>& e, int nE) {
    sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
        return a.u < b.u;
        });
}

bool DFS(int v, vector<vector<int>>& tree, vector<bool>& visited, int parent) {
    visited[v] = true;
    for (int u : tree[v]) {
        if (!visited[u]) {
            if (DFS(u, tree, visited, v)) {
                return true;
            }
        }
        else if (u != parent) {
            return true;
        }
    }
    return false;
}

bool NotLoop(Graph& g, int u, int v) {
    vector<vector<int>> tree(g.vertices);
    for (const Edge& e : g.T) {
        tree[e.u].push_back(e.v);
        tree[e.v].push_back(e.u);
    }
    vector<bool> visited(g.vertices, false);
    return DFS(u, tree, visited, -1);
}

void Kruskal(Graph g, int& nT, vector<Edge>& T) {
    int nEdge;
    vector<Edge> listE;

    Init_Arr_Edge(nEdge, listE, g);
    Sort_Edge(listE, nEdge); // S?a truy?n vào s? c?nh

    nT = 0;
    int iMin = 0;

    while (nT < g.vertices - 1 && iMin < nEdge) {
        int u = listE[iMin].u;
        int v = listE[iMin].v;

        if (!NotLoop(g, u, v)) {
            T.push_back(listE[iMin]);
            nT++;
        }
        iMin++;
    }
}

void edgeTree(vector<Edge>& e, ostream& os) {
    for (size_t i = 0; i < e.size(); i++) {
        os << "(" << e[i].u << "," << e[i].v << ") : " << e[i].w;
        if (i != e.size() - 1) os << "; ";
    }
    os << "\n";
}

int SumT(vector<Edge>& e) {
    int totalW = 0;
    for (int i = 0; i < e.size(); i++) {
        totalW += e[i].w;
    }
    return totalW;
}

void printSpanningTree(Graph& g, string fn) {
    ofstream f(fn);
    if (f.is_open()) {
        int nT = 0;
        Kruskal(g, nT, g.T);

        f << "Do thi co ma tran la:\n";
        for (int i = 0; i < g.vertices; i++) { 
            for (int j = 0; j < g.vertices; j++) {
                f << setw(4) << g.saveMatrix[i][j];
            }
            f << "\n";
        }
        f << "Tong cua trong so cua do thi cay khung la: " << SumT(g.T) << "\n";
        f << "Cac canh cua cay khung:\n";
        edgeTree(g.T, f);
        f.close();
    }
    else {
        cout << "Khong mo duoc file output!!" << endl;
    }
}

int main() {
    Graph g;
    readGraph(g, "input.txt");
    printSpanningTree(g, "output.txt");
    return 0;
}

*/
