#include <iostream>
#include <string>
using namespace std;

struct SMG {
    string id, phone, home_network;
    
    void nhap_SMG() {
        cin >> id >> phone >> home_network;
    }
    void xuat_SMG() {
        cout << id << ":" << phone << ":" << home_network << "\n";
    }
};
struct Gateway {
    SMG smg[10];
    string target;
    int size;
    
    void operator = (Gateway gw) {
        size = gw.size;
        target = gw.target;
        
        for(int i = 0; i < gw.size; i++) {
            smg[i] = gw.smg[i];
        }
    }
    SMG& operator[](int index) {
        return smg[index];
    }
    
    friend istream& operator >> (istream& is, Gateway& gw) {
        is >> gw.size;
        for(int i = 0; i < gw.size; i++) {
            gw.smg[i].nhap_SMG();
        }
        is >> gw.target;
        return is;
    }
    friend ostream& operator << (ostream& os, Gateway gw) {
        for(int i = 0; i < gw.size; i++) {
            string Num = gw.smg[i].phone.substr(0,3);
            string User = gw.target.substr(0,3);
            if(User == Num) {
                gw.smg[i].xuat_SMG();
            }
        }
        return os;
    }
};

void nhap(Gateway &gw) {
    cin >> gw;
}

void xuat(Gateway &gw) {
    cout << gw;
}
int main() {
    Gateway gw;
    
    nhap(gw);
    xuat(gw);
    
    return 0;
}
