#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Diem
{
    int x, y;

    void operator = (int)
    {
        x = 0;
        y = 0;
    }

    friend istream& operator >> (istream& is, Diem& d)
    {
        is >> d.x >> d.y;
        return is;
    }
    friend ostream& operator << (ostream& os, Diem d)
    {
        os << "(" << d.x << "," << d.y << ")";
        return os;
    }
    double operator - (Diem d)
    {
        return sqrt(pow(d.x - this->x,2) + pow(d.y - this->y,2));
    }

    double operator == (Diem d)
    {
        return this->x == d.x && this->y == d.y;
    }
};

struct DuongTron
{
    Diem ToaDo;
    double BanKinh;

    double ChuVi()
    {
        return 2 * 3.14 * this->BanKinh;
    }

    double DienTich()
    {
        return 3.14 * this->BanKinh * this->BanKinh;
    }

    friend istream& operator >> (istream& is, DuongTron& dt)
    {
        is >> dt.ToaDo >> dt.BanKinh;
        return is;
    }

    friend ostream& operator << (ostream& os, DuongTron dt)
    {
        os << dt.ToaDo << " " << dt.BanKinh;
        return os;
    }

    bool operator == (DuongTron dt)
    {
        return this->ChuVi() == dt.ChuVi();
    }

    bool operator > (DuongTron dt)
    {
        return this->ChuVi() > dt.ChuVi();
    }
};


string VitriTuongdoi(DuongTron a, DuongTron b)
{
    double KhoangCachTam = a.ToaDo - b.ToaDo;

    if (KhoangCachTam == 0) return "DT";
    if (abs(a.BanKinh - b.BanKinh) < KhoangCachTam && KhoangCachTam < a.BanKinh + b.BanKinh) return "C";
    if (abs(a.BanKinh - b.BanKinh) == KhoangCachTam) return "TXT";
    if (abs(a.BanKinh - b.BanKinh) > KhoangCachTam) return "DN";
    if (a.BanKinh + b.BanKinh == KhoangCachTam) return "TXN";
    if (a.BanKinh + b.BanKinh < KhoangCachTam) return "NN";
}


int main()
{
    DuongTron a, b;
    cin >> a >> b;

    cout << a << "\n" << b << "\n";
    double kq = a.DienTich() + b.DienTich();

    cout << roundf(kq * 1000) / 1000 << "\n";

    if (a.ChuVi() == b.ChuVi())
        cout << "1 = 2";
    else if (a.ChuVi() < b.ChuVi())
        cout << "1 < 2"; 
    else if (a.ChuVi() > b.ChuVi())
        cout << "1 > 2";

    cout << "\n" << VitriTuongdoi(a, b);

    return 0;

}
