/* Đề bài:
1.Kiểm tra vô hướng
2.Tìm số cạnh
3.Cạnh có trọng số lớn nhất
4.Tìm bán bậc ra và bán bậc vào của tất cả các đỉnh
5.Tìm đỉnh có bậc lớn nhất/nhỏ nhất, đỉnh bậc chẵn và đỉnh bậc lẻ của đồ thị
6.Tìm đỉnh treo, đỉnh cô lập (nếu có).

"input.txt"
7
0 2 0 4 0 0 0
2 0 -3 1 2 0 0
0 -3 0 2 2 0 0
4 1 2 0 0 0 0 
0 2 2 0 0 1 0
0 0 0 0 1 0 0 
0 0 0 0 0 0 0

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct Graph {
	int sodinh;
	int a[MAX][MAX];
	int bac[MAX];
};

void readGraph(string fis, Graph& g) {
	ifstream ifs;
	ifs.open(fis);

	if (ifs.is_open()) {
		ifs >> g.sodinh;
		for (int i = 0; i < g.sodinh; i++) {
			for (int j = 0; j < g.sodinh; j++) {
				ifs >> g.a[i][j];
			}
		}
	}
	else cout << "Khong mo duoc file input!";
}

bool KtraVoHuong(Graph g) {
	for (int i = 0; i < g.sodinh; i++) {
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != g.a[j][i])
				return false;
		}
	}
	return true;
}

void demSoCanh(Graph g, ostream& ofs) {
	int dem = 0;

	if (KtraVoHuong(g)) {
		for (int i = 0; i < g.sodinh; i++) {
			for (int j = i; j < g.sodinh; j++) {
				if (g.a[i][j] != 0)
					dem++;
			}
		}
	}
	else {
		for (int i = 0; i < g.sodinh; i++) {
			for (int j = 0; j < g.sodinh; j++) {
				if (g.a[i][j] != 0) {
					dem++;
				}
			}
		}
	}
	ofs << "So canh cua do thi la: " << dem << "\n";
}

void timCanhDaiNhat(Graph g, ostream& ofs) {
	int max = 0;
	for (int i = 0; i < g.sodinh; i++) {
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] > max)
				max = g.a[i][j];
		}
	}
	ofs << "Canh dai nhat co trong so la: " << max << "\n\n";
}

void bacCuaTatCaDinh(Graph g, ostream& ofs) {
	for (int i = 0; i < g.sodinh; i++) {
		g.bac[i] = 0;
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0)
				g.bac[i]++;
		}
		ofs << "Dinh " << i + 1 << " co bac la: " << g.bac[i] << "\n\n";
	}
}

void BanBacVaoBanBacRa(Graph g, ostream& ofs) {
	int banBacVao[MAX];
	int banBacRa[MAX];

	for (int i = 0; i < g.sodinh; i++) {
		banBacRa[i] = 0;
		banBacVao[i] = 0;
	}

	for (int i = 0; i < g.sodinh; i++) {
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0) {
				banBacRa[i]++;
				banBacVao[i]++;
			}
		}
	}

	for (int i = 0; i < g.sodinh; i++) {
		ofs << "Dinh " << i + 1 << " co ban bac ra la " << banBacRa[i] << "\n";
		ofs << "Dinh " << i + 1 << " co ban bac vao la " << banBacVao[i] << "\n";
	}
}

void dinhCoBacLonNhat(Graph g, ostream& ofs) {
	int maxBac = 0;
	int dinh[MAX];
	int soDinh = 0;

	for (int i = 0; i < g.sodinh; i++) {
		int bacRa = 0, bacVao = 0;

		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0)
				bacRa++;
		}
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[j][i] != 0)
				bacVao++;
		}

		int bac = bacRa + bacVao;

		if (bac > maxBac) {
			maxBac = bac;
			soDinh = 1;
			dinh[0] = i;
		}
		else if (bac == maxBac) {
			dinh[soDinh] = i;
			soDinh++;
		}
	}

	ofs << "Cac dinh co bac lon nhat la: ";
	for (int i = 0; i < soDinh; i++) {
		ofs << dinh[i] + 1;
		if (i < soDinh - 1)
			ofs << ", ";
	}
	ofs << "\n";
}

void dinhCoBacNhoNhat(Graph g, ostream& ofs) {
	int minBac = INT_MAX;
	int dinh[MAX];
	int soDinh = 0;

	for (int i = 0; i < g.sodinh; i++) {
		int bacRa = 0, bacVao = 0;

		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0)
				bacRa++;
		}

		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[j][i] != 0)
				bacVao++;
		}
		
		int bac = bacRa + bacVao;
		
		if (minBac > bac) {
			minBac = bac;
			soDinh = 1;
			dinh[0] = i;
		}
		else if (bac == minBac) {
			dinh[soDinh] = i;
			soDinh++;
		}
	}

	ofs << "Cac dinh co bac nho nhat la: ";
	for (int i = 0; i < soDinh; i++) {
		ofs << dinh[i] + 1;
		if (i < soDinh - 1)
			ofs << ", ";
	}
	ofs << "\n\n";
}

void timDinhBacLe(Graph g, ostream& ofs) {
	ofs << "Cac dinh co bac le la: ";
	bool found = false;

	for (int i = 0; i < g.sodinh; i++) {
		int bac = 0;
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0)
				bac++;
		}

		if (bac % 2 != 0) {
			ofs << i + 1 << " ";
			found = true;
		}
	}

	if (!found) ofs << "Khong tim thay dinh bac le!\n\n";
	else ofs << "\n\n";
}

void timBanBacVaoLe(Graph g, ostream& ofs) {
	ofs << "Cac dinh co ban bac vao le la: ";
	bool found = false;

	for (int i = 0; i < g.sodinh; i++) {
		int banBacVao = 0;
		for (int j = 0; j < g.sodinh; j++) {
			if(g.a[j][i] != 0)
				banBacVao++;
		}
		if (banBacVao % 2 != 0) {
			ofs << i + 1 << " ";
			found = true;
		}
	}
	if (!found) ofs << "Khong tim thay dinh co ban bac vao le!\n\n";
	else ofs << "\n\n";
}
void timBanBacRaLe(Graph g, ostream& ofs) {
	ofs << "Cac dinh co ban bac ra le la: ";
	bool found = false;

	for (int i = 0; i < g.sodinh; i++) {
		int banBacRa = 0;
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0)
				banBacRa++;
		}

		if (banBacRa % 2 != 0) {
			ofs << i + 1 << " ";
			found = true;
		}
	}
	if (!found) ofs << "Khong tim thay dinh co ban bac ra le!\n\n";
	else ofs << "\n\n";
}

void timDinhBacChan(Graph g, ostream& ofs) {
	ofs << "Cac dinh co bac chan la: ";
	bool found = false;

	for (int i = 0; i < g.sodinh; i++) {
		int bac = 0;
		for (int j = 0; j < g.sodinh; j++) {
			if(g.a[i][j] != 0) 
				bac++;
		}
		if (bac % 2 == 0) {
			ofs << i + 1 << " ";
			found = true;
		}
	}
	if (!found) ofs << "Khong tim thay dinh bac chan!\n\n";
	else ofs << "\n\n";
}
void timBanBacVaoChan(Graph g, ostream& ofs) {
	ofs << "Cac dinh co ban bac vao chan la: ";
	bool found = false;

	for (int i = 0; i < g.sodinh; i++) {
		int banBacVao = 0;
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[j][i])
				banBacVao++;
		}
		if (banBacVao % 2 == 0) {
			ofs << i + 1 << " ";
			found = true;
		}
	}

	if (!found) ofs << "Khong tim thay dinh co ban bac vao chan!\n\n";
	else ofs << "\n\n";
}
void timBanBacRaChan(Graph g, ostream& ofs) {
	ofs << "Cac dinh co ban bac ra chan la: ";
	bool found = false;

	for (int i = 0; i < g.sodinh; i++) {
		int banBacRa = 0;
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0)
				banBacRa++;
		}
		if (banBacRa % 2 == 0) {
			ofs << i + 1 << " ";
			found = true;
		}
	}
	if (!found) ofs << "Khong tim duoc dinh nao co ban bac ra chan!\n\n";
	else ofs << "\n\n";
}

void timDinhTreo(Graph g, ostream& ofs) {
	ofs << "Cac dinh treo la: ";
	bool found = false;

	for (int i = 0; i < g.sodinh; i++) {
		int banBacRa = 0, banBacVao = 0;

		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0)
				banBacRa++;
		}
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[j][i])
				banBacVao++;
		}

		if (KtraVoHuong(g)) {
			if (banBacRa == 1) {
				ofs << i + 1 << " ";
				found = true;
			}
		}
		else {
			if (banBacRa + banBacVao == 1) {
				ofs << i + 1 << " ";
				found = true;
			}
		}
	}
	if (!found) ofs << "Khong tim thay dinh treo!\n\n";
	else ofs << "\n\n";
}
void timDinhCoLap(Graph g, ostream& ofs) {
	ofs << "Cac dinh co lap la: ";
	bool found = false;
	
	for (int i = 0; i < g.sodinh; i++) {
		int banBacVao = 0, banBacRa = 0;
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0)
				banBacRa++;
		}
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[j][i])
				banBacVao++;
		}

		if (KtraVoHuong(g)) {
			if (banBacRa == 0) {
				ofs << i + 1 << " ";
				found = true;
			}
		}
		else {
			if (banBacRa + banBacVao == 0) {
				ofs << i + 1 << " ";
				found = true;
			}
		}
	}
	if (!found) ofs << "Khong tim thay dinh co lap!" << "\n\n";
	else ofs << "\n\n";
}

void printGraph(string fos, Graph g) {
	ofstream ofs;
	ofs.open(fos);

	if (ofs.is_open()) {
		ofs << "So dinh cua do thi: " << g.sodinh << "\n";

		for (int i = 0; i < g.sodinh; i++) {
			for (int j = 0; j < g.sodinh; j++) {
				ofs << setw(4) << g.a[i][j];
			}
			ofs << "\n";
		}

		if (KtraVoHuong(g)) ofs << "\nDo thi nay vo huong!\n\n";
		else ofs << "Do thi nay co huong!\n\n";

		demSoCanh(g, ofs);
		timCanhDaiNhat(g, ofs);

		if (KtraVoHuong(g)) bacCuaTatCaDinh(g,ofs);
		else ofs << "";

		dinhCoBacLonNhat(g, ofs);
		dinhCoBacNhoNhat(g, ofs);

		if (KtraVoHuong(g)) timDinhBacChan(g, ofs);
		else {
			timBanBacRaChan(g, ofs);
			timBanBacVaoChan(g, ofs);
		}

		if (KtraVoHuong(g)) timDinhBacLe(g, ofs);
		else {
			timBanBacRaLe(g, ofs);
			timBanBacVaoLe(g, ofs);
		}

		timDinhTreo(g, ofs);
		timDinhCoLap(g, ofs);
	}
	else cout << "Khong mo duoc file output!";
	ofs.close();
}

int main() {
	Graph graph;
	readGraph("input.txt", graph);
	printGraph("output.txt", graph);

	return 0;
}
