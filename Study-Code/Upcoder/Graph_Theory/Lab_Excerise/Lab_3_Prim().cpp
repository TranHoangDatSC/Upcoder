#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <iomanip>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

struct Graph {
    int sodinh;
    vector<vector<int>> a;
    vector<Edge> T;
    Graph() : sodinh(0), a() {}
};

vector<bool> visited;

void readGraph(Graph& g, string fn) {
    ifstream f(fn);
    if (f.is_open()) {
        f >> g.sodinh;
        g.a.resize(g.sodinh, vector<int>(g.sodinh, 0));
        visited.resize(g.sodinh, false);
        for (int i = 0; i < g.sodinh; i++) {
            for (int j = 0; j < g.sodinh; j++) {
                f >> g.a[i][j];
            }
        }
        f.close();
    }
    else {
        cout << "Khong mo duoc file input!";
    }
}
Edge findMinEdge(const vector<Edge>& e) {
    if (e.empty()) {
        return { -1, -1, INT_MAX };
    }
    Edge minEdge = e[0];
    for (int i = 1; i < e.size(); i++) {
        if (minEdge.w > e[i].w) {
            minEdge = e[i];
        }
    }
    return minEdge;
}

void Prim(Graph& g) {
    visited[0] = true;
    int nT = 0;

    while (nT < g.sodinh - 1) {
        vector<Edge> e;

        for (int i = 0; i < g.sodinh; i++) {
            if (visited[i]) {
                for (int j = 0; j < g.sodinh; j++) {
                    if (!visited[j] && g.a[i][j] != 0) {
                        e.push_back({ i, j, g.a[i][j] });
                    }
                }
            }
        }

        if (e.empty()) break;

        Edge minEdge = findMinEdge(e);
        g.T.push_back(minEdge);
        visited[minEdge.v] = true;
        nT++;
    }
}

Edge findMaxEdge(const vector<Edge>& e) {
    Edge maxEdge = e[0];
    for (int i = 1; i < e.size(); i++) {
        if (maxEdge.w < e[i].w) {
            maxEdge = e[i];
        }
    }
    return maxEdge;
}

int SumT(const vector<Edge>& e) {
    int totalW = 0;
    for (const auto& edge : e) {
        totalW += edge.w;
    }
    return totalW;
}

void Edges_in_Graph(const vector<Edge>& e, ostream& os) {
    for (const auto& edge : e) {
        os << "(" << edge.u + 1 << "," << edge.v + 1 << ") : " << edge.w << "\n";
    }
}

void Max_Min_Edge(const vector<Edge>& e, ostream& os) {
    Edge maxEdge = findMaxEdge(e);
    Edge minEdge = findMinEdge(e);

    os << "Canh nho nhat: (" << minEdge.u + 1 << "," << minEdge.v + 1 << ") \n";
    os << "Canh lon nhat: (" << maxEdge.u + 1 << "," << maxEdge.v + 1 << ") \n";
}

void drawGraph(const Graph& g, ostream& os) {
    os << "Do thi cay khung nho nhat co ma tran la:\n";
    vector<vector<int>> spanningMatrix(g.sodinh, vector<int>(g.sodinh, 0));

    for (const auto& edge : g.T) {
        spanningMatrix[edge.u][edge.v] = edge.w;
        spanningMatrix[edge.v][edge.u] = edge.w; 
    }

    for (int i = 0; i < g.sodinh; i++) {
        for (int j = 0; j < g.sodinh; j++) {
            os << setw(4) << spanningMatrix[i][j];
        }
        os << "\n";
    }
}

void printSpanningTree(Graph& g, string fn) {
    ofstream os(fn);

    if (os.is_open()) {
        Prim(g);
        os << "Tong trong so cua cay khung nho nhat: " << SumT(g.T) << "\n";
        os << "Cac canh trong cay khung nho nhat:\n";
        Edges_in_Graph(g.T, os);
        Max_Min_Edge(g.T, os);
        drawGraph(g, os);
        os.close();
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
