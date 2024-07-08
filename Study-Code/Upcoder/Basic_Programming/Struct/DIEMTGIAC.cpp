#include <iostream>
#include <cmath>
using namespace std;

struct Diem {
    int x,y;
    
    void nhap_diem() {
        cin >> x >> y;
    }
    void xuat_diem() {
        cout << "(" << x << "," << y << ") ";
    }
    double Range(Diem other) {
        return sqrt(pow(other.x - this->x,2) + pow(other.y - this->y,2)); 
    }
    bool TrungDiem(Diem other) {
        return this->x==other.x && this->y==other.y;
    }
};
struct TamGiac {
    Diem a,b,c;
    
    friend istream& operator >> (istream& is, TamGiac& tg)
    {
        tg.a.nhap_diem();
        tg.b.nhap_diem();
        tg.c.nhap_diem();
        return is;
    }
    friend ostream& operator << (ostream& os, TamGiac tg)
    {
        tg.a.xuat_diem();
        tg.b.xuat_diem();
        tg.c.xuat_diem();
        return os;
    }
    
    double ChuVi() {
        return a.Range(b) + c.Range(a) + b.Range(c);
    }
    bool checkCV(TamGiac other) {
        if(this->ChuVi() < other.ChuVi()) 
            return true;
        else return false;
    }
    bool TrungTG(TamGiac other) {
        if((this->a.TrungDiem(other.a) || this->a.TrungDiem(other.b) || this->a.TrungDiem(other.c)) && 
        (this->b.TrungDiem(other.a) || this->b.TrungDiem(other.b) || this->b.TrungDiem(other.c)) &&
        (this->c.TrungDiem(other.a) || this->c.TrungDiem(other.b) || this->c.TrungDiem(other.c))) return true;
        else return false;
    }
    
};

void nhap(TamGiac &a, TamGiac &b) {
    cin >> a >> b;
}
void xuat(TamGiac a, TamGiac b) {
    cout << a << "\n" << b;
    cout << (a.checkCV(b) ? "\nTRUE\n" : "\nFALSE\n");
    cout << (a.TrungTG(b) ? "TRUE" : "FALSE");
}

int main()
{
    TamGiac a,b;
    nhap(a,b);
    xuat(a,b);
    return 0;
}
