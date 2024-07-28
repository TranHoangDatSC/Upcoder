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
        os << ps.tu << "/" << ps.mau;
        return os;
    }

    void RutGon() {
        int d = gcd(this->tu, this->mau);
        this->tu /= d;
        this->mau /= d;
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
        cout << -1 << endl;
        return 0;
    }

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    return 0;
}
