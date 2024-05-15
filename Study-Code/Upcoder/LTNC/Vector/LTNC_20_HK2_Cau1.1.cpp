#include <bits/stdc++.h>

using namespace std;

struct PhanSo{
    int tu, mau;
    PhanSo(int x = 0, int y = 1){
        tu = x;
        mau = y;
    }
};

istream& operator >> (istream &is, PhanSo &p);
ostream& operator << (ostream &os, PhanSo p);
bool operator < (PhanSo p1, PhanSo p2);
bool operator > (PhanSo p1, PhanSo p2);
PhanSo operator + (PhanSo p1, PhanSo p2);
PhanSo operator * (PhanSo p1, PhanSo p2);
bool ktPhanSoDep(PhanSo p);
PhanSo rutGon(PhanSo p);

int main(){
    freopen("EM_SE_CO_GANG_LAM_BAI_TOT.INP", "r", stdin);
    freopen("EM_XIN_HUA_LAM_BAI_NGHIEM_TUC.OUT", "w", stdout);
    PhanSo tmp, tong = 0, tich = 1;
    vector<PhanSo> v, v1, v2;
    ostream_iterator<PhanSo> output(cout, " ");
    
    while (cin >> tmp) {
        v.push_back(tmp);
        if (ktPhanSoDep(tmp)) {
            v1.push_back(tmp);
            tong = tong + tmp;
        }
        else {
            v2.push_back(tmp);
            tich = tich * tmp;
        }
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<PhanSo>());
    
    copy_if(v.begin(), v.end(), output, 
                [v](PhanSo &a){ return (&a - &v[0]) % 2 == 0; });
    copy_if(v.begin(), v.end(), output, 
                [v](PhanSo &a){ return (&a - &v[0]) % 2 != 0; });
    
    cout << endl;
    cout << v1.back() << " " << tong << endl;
    cout << v2.back() << " " << tich << endl;
    
    copy(v1.begin(), v1.end(), output);
    cout << endl;
    copy(v2.begin(), v2.end(), output);
    
    return 0;
}

istream& operator >> (istream &is, PhanSo &p){
    is >> p.tu >> p.mau;
    return is;
}
ostream& operator << (ostream &os, PhanSo p){
    os << p.tu << "/" << p.mau;
    return os;
}
bool operator < (PhanSo p1, PhanSo p2){
    double x = (double)p1.tu/p1.mau;
    double y = (double)p2.tu/p2.mau;
    return (x < y || (x == y && p1.tu < p2.tu));
}
bool operator > (PhanSo p1, PhanSo p2){
    double x = (double)p1.tu/p1.mau;
    double y = (double)p2.tu/p2.mau;
    return (x > y || (x == y && p1.tu > p2.tu));
}
PhanSo operator + (PhanSo p1, PhanSo p2){
    return rutGon(PhanSo(p1.tu*p2.mau + p2.tu*p1.mau, p1.mau*p2.mau));
}
PhanSo operator * (PhanSo p1, PhanSo p2){
    return rutGon(PhanSo(p1.tu*p2.tu, p1.mau*p2.mau));
}
bool ktPhanSoDep(PhanSo p){
    return (p.tu % 2 == 0 && p.mau % 2 == 0);
}
PhanSo rutGon(PhanSo p){
    int x = __gcd(p.tu, p.mau);
    return PhanSo(p.tu/x, p.mau/x);
}
