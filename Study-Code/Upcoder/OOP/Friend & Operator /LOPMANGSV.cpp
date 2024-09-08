#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Diem {
    private:
        int size;
        double mark[100];
    
    public:
        
        // Constructor
        Diem(int _size = 0, double _mark[] = new double {0}) {
            size = _size;
            for(int i = 0; i < size; i++) {
                mark[i] = _mark[i];
            }
        }
        Diem(const Diem& d) {
            size = d.size;
            for(int i = 0; i < size; i++) {
                mark[i] = d.mark[i];
            }
        }
        
        // Operator >> , <<, [], =
        friend istream& operator >> (istream& is, Diem& d) {
            d.size = 0;
            while(cin >> d.mark[d.size]) {
                d.size++;
            }
            return is;
        }
        friend ostream& operator << (ostream& os, Diem d) {
            for(int i = 0; i < d.size; i++) {
                os << d.mark[i] << " ";
            }
            return os;
        }
        double operator[] (int index) {
            return mark[index];
        }
        void operator = (Diem d) {
            size = d.size;
            for(int i = 0; i < size; i++) {
                mark[i] = d.mark[i];
            }
        }
        
        // Average Mark
        double DTB() {
            double sum = 0;
            for(int i = 0; i < this->size; i++) {
                sum += mark[i];
            }
            return sum / size;
        }
        
        // Get, set method
        void setSize(int _size) { size = _size; }
        void setMark(double _mark, int k) { mark[k] = _mark; }
        
        int getSize() { return this->size; }
        double getMark(int k) { return this->mark[k]; }
        
        // Destructor 
        ~Diem() {}
};

class SinhVien {
    private: 
        string hoten;
        string mssv;
        Diem diem;
        
    public:
        
        // Constructor
        SinhVien(string _hoten = "", string _mssv = "", Diem _diem = Diem()) {
            hoten = _hoten;
            mssv = _mssv;
            diem = _diem;
        }
        SinhVien(const SinhVien& sv) {
            hoten = sv.hoten;
            mssv = sv.mssv;
            diem = sv.diem;
        }
        
        // Operator >> , << , [] , = 
        friend istream& operator >> (istream& is, SinhVien& sv) {
            getline(is, sv.hoten);
            is >> sv.mssv;
            is >> sv.diem;
            return is;
        }
        friend ostream& operator << (ostream& os, SinhVien sv) {
            double tong = sv.diem.DTB();
            os << "Ho Ten: " << sv.hoten << "\n";
            os << "Ma Sinh Vien: " << sv.mssv << "\n";
            os << "DTB: " << setprecision(1) << fixed << tong;
            return os;
        }
        Diem operator[](int index) {
            return diem[index];
        }
        SinhVien& operator = (SinhVien sv) {
            hoten = sv.hoten;
            mssv = sv.mssv;
            diem = sv.diem;
            return *this;
        }
        
        // Get, set method
        void setHoten(string _hoten) { hoten = _hoten; }
        void setMssv(string _mssv) { mssv = _mssv; }
        void setDiem(Diem _diem) { diem = _diem; }
        
        string getHoten() { return hoten; }
        string getMssv() { return mssv; }
        Diem getDiem() { return diem; } 
        
        // Average Mark of all Average mark of Student
        double getAvg() {
            return diem.DTB();
        }
        
        // Student with Highest Avg Mark 
        bool operator < (SinhVien other) {
            if(this->getAvg() < other.getAvg()) {
                return true;
            }
            return false;
        }
        // Destructor
        ~SinhVien() {}
};

class MangSinhVien {
    private:
        int sizeM;
        SinhVien arrM[100];
    
    public:
        
        // Constructor
        MangSinhVien(int _sizeM = 0, SinhVien _arrM[] = new SinhVien{}) {
            sizeM = _sizeM;
            for(int i = 0; i < sizeM; i++) {
                arrM[i] = _arrM[i];
            }
        }
        MangSinhVien(const MangSinhVien& msv) {
            sizeM = msv.sizeM;
            for(int i = 0; i < sizeM; i++) {
                arrM[i] = msv.arrM[i];
            }
        }
        
        // Operator >> , << 
        friend istream& operator >> (istream& is, MangSinhVien& msv) {
            is >> msv.sizeM;
            is.ignore();
            for(int i = 0; i < msv.sizeM; i++) {
                is >> msv.arrM[i];
                is.clear();
            }
            return is;
        }
        friend ostream& operator << (ostream& os, MangSinhVien msv) {
            SinhVien Max = msv.arrM[0];
            
            for(int i = 0; i < msv.sizeM; i++) {
                if(Max < msv.arrM[i])
                    Max = msv.arrM[i];
            }
            os << Max;
            return os;
        }
        
        // Get, set method
        void setSizeM(int _sizeM) { sizeM = _sizeM; }
        void setArrM(SinhVien _arrM, int k) { arrM[k] = _arrM; }
        
        int getSizeM() { return sizeM; }
        SinhVien getArrM(int k) { return arrM[k]; }
        
        // Destructor
        ~MangSinhVien() {}
};

int main() {
    MangSinhVien msv;
    cin >> msv;
    cout << msv;
    return 0;
}
