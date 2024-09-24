/*
Đề bài:
1.Xét tính liên thông ghi kết quả vào file output.txt
2.Cần bao nhiêu cạnh để đt liên thông, đó là những cạnh nào?
3.Duyệt BFS với đồ thị trên bảng kq: 0 1 5 2 3 6 4 7

"input.txt"
8
0 1 0 0 0 1 0 0
1 0 1 1 0 0 0 0 
0 1 0 0 1 0 0 0 
0 1 0 0 0 0 0 0
0 0	1 0 0 0 0 0
1 0 0 0 0 0 1 0
0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0
0 7
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 100;

int mienLienThong;
int visited[MAX];
int LuuVet[MAX];
int cntSave = 0;
vector<int> save;

int Start, End;

struct Graph {
	int sodinh;
	int a[MAX][MAX];
	int bac[MAX];
};

void readGraph(string fis, string fos, Graph& g) {
	ifstream ifs;
	ifs.open(fis);

	if (ifs.is_open()) {
		ifs >> g.sodinh;

		for (int i = 0; i < g.sodinh; i++) {
			for (int j = 0; j < g.sodinh; j++) {
				ifs >> g.a[i][j];
			}
		}
		ifs >> Start >> End;
	}
	else {
		ofstream ofs;
		ofs.open(fos);

		if (ofs.is_open()) ofs << "Khong mo duoc file!";
		else cout << "khong mo duoc file de ghi ket qua!";

		ofs.close();
	}
	ifs.close();
}

void printGraph(Graph g, string fos) {
	ofstream ofs;
	ofs.open(fos, ios::app);

	if (ofs.is_open()) {
		ofs << "Do thi la: " << "\n";

		for (int i = 0; i < g.sodinh; i++) {
			for (int j = 0; j < g.sodinh; j++) {
				ofs << setw(4) << g.a[i][j] << " ";
			}
			ofs << "\n";
		}
		ofs << "\n";
		ofs << "So dinh cua do thi: " << g.sodinh << "\n\n";
	}
	else {
		cout << "Khong mo duoc file de ghi ket qua!";
	}
	ofs.close();
}

void BFS(Graph g, int i, int mienLienThong) {
	queue<int> q;
	q.push(i);

	visited[i] = mienLienThong;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		save.push_back(u);

		for (int v = 0; v < g.sodinh; v++) {
			if (visited[v] == 0 && g.a[u][v] != 0) {
				visited[v] = mienLienThong;
				q.push(v);
				LuuVet[v] = u;
			}
		}
	}
}

void xetLienThong(Graph g) {
	mienLienThong = 0;

	for (int i = 0; i < g.sodinh; i++) {
		if (visited[i] == 0) {
			mienLienThong++;
			BFS(g, i, mienLienThong);
		}
	}
}

void printThanhPhanLienThong(Graph& g, string fos) {
	ofstream ofs;
	ofs.open(fos, ios::app);

	if (ofs.is_open()) {
		ofs << "So mien lien thong: " << mienLienThong << "\n\n";

		if (mienLienThong == 1) ofs << "Do thi lien thong!\n";
		else ofs << "Do thi khong lien thong!\n";

		for (int i = 1; i <= mienLienThong; i++) {
			ofs << "Thanh phan lien thong so " << i << ":\n";

			for (int j = 0; j < g.sodinh; j++) {
				if (visited[j] == i)
					ofs << j << setw(4);
			}
			ofs << "\n";
		}
	}
	else cout << "Khong mo duoc file de ghi ket qua!";

	ofs.close();
}
void canhDeLienThong(Graph g, string fos) {
	ofstream ofs;
	ofs.open(fos, ios::app);

	if (ofs.is_open()) {
		if (mienLienThong > 1)
		{
			ofs << "Cac canh can them de do thi lien thong la:\n";

			vector<vector<int>> cacThanhPhan(mienLienThong);
			for (int i = 0; i < g.sodinh; i++) {
				cacThanhPhan[visited[i] - 1].push_back(i);
			}

			int canhCanThem = 0;
			for (int i = 0; i < cacThanhPhan.size() - 1; i++) {
				for (int j = i + 1; j < cacThanhPhan.size(); j++) {
					for (int u : cacThanhPhan[i]) {
						for (int v : cacThanhPhan[j]) {
							ofs << "Canh: (" << u << "," << v << ")\n";
							canhCanThem++;
						}
					}
				}
			}
			ofs << "So canh can them de lien thong do thi: " << canhCanThem << "\n";
		}
		else
			ofs << "Do thi da lien thong, khong can them canh de lien thong do thi!";
	}
	else {
		cout << "Khong mo duoc file de ghi ket qua!";
	}
	ofs.close();
}

void duyetBFS(Graph g,string fos) {
	ofstream ofs;
	ofs.open(fos, ios::app);

	ofs << "\n";
	if (ofs.is_open()) {
		if (!save.empty()) {
			for (int i = 0; i < save.size(); i++) {
				ofs << save[i];
				if (i != save.size() - 1) {
					ofs << " <-- ";
				}
			}
		}
		else ofs << "Khong co duong di tu " << Start << " den " << End;
	}
	else cout << "Khong mo duoc file de ghi ket qua!";
	ofs.close();
}


int main() {
	Graph graph;

	readGraph("input.txt", "output.txt", graph);
	printGraph(graph, "output.txt");

	xetLienThong(graph);
	printThanhPhanLienThong(graph, "output.txt");
	canhDeLienThong(graph, "output.txt");

	duyetBFS(graph, "output.txt");

	return 0;
}
