#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct PhanSo {
    int tu, mau;

    friend istream& operator >> (istream& is, PhanSo& ps) {
        is >> ps.tu >> ps.mau;
        return is;
    }

    friend ostream& operator << (ostream& os, PhanSo ps) {
        if(ps.tu == 0) os << 0;
        
        else os << ps.tu << "/" << ps.mau;
        
        return os;
    }

    void RutGon() {
        int d = gcd(this->tu, this->mau);
        this->tu /= d;
        this->mau /= d;
        
        if(this->mau < 0) {
            this->tu = -this->tu;
            this->mau = -this->mau;
        }
    }

    PhanSo operator + (PhanSo other) {
        PhanSo kq;
        kq.tu = this->tu * other.mau + this->mau * other.tu;
        kq.mau = this->mau * other.mau;
        kq.RutGon();
        return kq;
    }

    PhanSo operator - (PhanSo other) {
        PhanSo kq;
        kq.tu = this->tu * other.mau - this->mau * other.tu;
        kq.mau = this->mau * other.mau;
        kq.RutGon();
        return kq;
    }

    PhanSo operator * (PhanSo other) {
        PhanSo kq;
        kq.tu = this->tu * other.tu;
        kq.mau = this->mau * other.mau;
        kq.RutGon();
        return kq;
    }

    PhanSo operator / (PhanSo other) {
        PhanSo kq;
        kq.tu = this->tu * other.mau;
        kq.mau = this->mau * other.tu;
        kq.RutGon();
        return kq;
    }
};

int main() {
    PhanSo a, b;
    cin >> a >> b;

    if (a.mau == 0 || b.mau == 0) {
        cout << -1;
        return 0;
    }

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    if(b.tu != 0) cout << a / b;

    return 0;
}


/*

#include <iostream>
#include <algorithm>

using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

// Hàm tìm ước chung lớn nhất (gcd)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Hàm rút gọn phân số
PhanSo rutGon(PhanSo ps) {
    int ucln = gcd(abs(ps.tu), abs(ps.mau));
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) { // Đảm bảo mẫu số luôn dương
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}

// Hàm cộng hai phân số
PhanSo tong(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu = a.tu * b.mau + b.tu * a.mau;
    ketQua.mau = a.mau * b.mau;
    return rutGon(ketQua);
}

// Hàm trừ hai phân số
PhanSo hieu(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu = a.tu * b.mau - b.tu * a.mau;
    ketQua.mau = a.mau * b.mau;
    return rutGon(ketQua);
}

// Hàm nhân hai phân số
PhanSo tich(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu = a.tu * b.tu;
    ketQua.mau = a.mau * b.mau;
    return rutGon(ketQua);
}

// Hàm chia hai phân số
PhanSo thuong(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu = a.tu * b.mau;
    ketQua.mau = a.mau * b.tu;
    return rutGon(ketQua);
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo ps) {
    if (ps.tu == 0) {
        cout << "0" << endl;
    } else {
        cout << ps.tu << "/" << ps.mau << endl;
    }
}

int main() {
    PhanSo a, b;
    cin >> a.tu >> a.mau;
    cin >> b.tu >> b.mau;

    if (a.mau == 0 || b.mau == 0) {
        cout << "-1" << endl;
        return 0;
    }

    PhanSo ketQua;

    // Tính tổng
    ketQua = tong(a, b);
    xuatPhanSo(ketQua);

    // Tính hiệu
    ketQua = hieu(a, b);
    xuatPhanSo(ketQua);

    // Tính tích
    ketQua = tich(a, b);
    xuatPhanSo(ketQua);

    // Tính thương nếu B khác 0
    if (b.tu != 0) {
        ketQua = thuong(a, b);
        xuatPhanSo(ketQua);
    }

    return 0;
}
*/
