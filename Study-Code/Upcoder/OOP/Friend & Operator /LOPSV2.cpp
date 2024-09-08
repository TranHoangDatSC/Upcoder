#include <iostream>
#include <iomanip> 
using namespace std;

class Diem {
    private:
        int size;
        double mark[100];
    
    public:
        
        // Xây dựng các toán tử >>, <<, [], = 
        friend istream& operator >> (istream& is, Diem& d) {
            d.size = 0;
            
            while(is >> d.mark[d.size]) {
                d.size++;
            }
            return is;
        }
        
        friend ostream& operator << (ostream& os, Diem d) {
            for(int i = 0; i < d.size; i++) {
                os << d.mark[i];
            }
            return os;
        }
        double operator[](int index) {
            return mark[index];
        }
        void operator = (Diem d) {
            size = d.size;
            for(int i = 0;i < size; i++) {
                mark[i] = d.mark[i];
            }
        }
        
        // Lấy điểm trung bình cộng
        double DTB() {
            double sum = 0;
            for(int i = 0;i < size; i++) {
                sum += mark[i];
            }
            return sum / size;
        }
        
        // Phương thức khởi tạo (3 phương thức)
        
        Diem(double _mark[] = new double {0}, int _size = 0) {
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
        
        // Phương thức hủy
        ~Diem() {}
        
        // Các phương thức get và set.
        void setSize(int _size) { size = _size; }
        void setMark(double _mark, int n) { mark[n] = _mark; }
        int getSize() { return this->size; }
        int getMark(int n) {return this->mark[n]; }
};

class SinhVien {
    private: 
        string hoten;
        string mssv;
        Diem diem;
    
    public: 
        
        // Xây dựng các toán tử >>, <<, =, <
        friend istream& operator >> (istream& is, SinhVien& sv) {
            getline(is,sv.hoten);
            is >> sv.mssv;
            is >> sv.diem;
            return is;
        }
        friend ostream& operator << (ostream& os, SinhVien sv) {
            double tong = sv.diem.DTB();
            os << "Ho Ten: " << sv.hoten << "\n";
            os << "Ma Sinh Vien: " << sv.mssv << "\n";
            os << "DTB: " << setprecision(1) << fixed << tong;
        }
        // Lấy điểm trung bình cộng đã có ở hàm trên rồi
        
        void operator = (SinhVien& sv) {
            hoten = sv.hoten;
            mssv = sv.mssv;
            diem = sv.diem;
        }
        bool operator < (SinhVien other) {
            return this->diem.DTB() < other.diem.DTB();
        }
        
        // Các phương thức khởi tạo (3 phương thức)
        
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
         // Phương thức hủy
        ~SinhVien() {}
        
        // Các phương thức get và set.
        void setHoten(string _hoten) { hoten = _hoten; }
        void setMssv(string _mssv) { mssv = _mssv; } 
        void setDiem(Diem _diem) { diem = _diem; }
        
        string getHoten() { return hoten; }
        string getMssv() { return mssv; }
        Diem getDiem() { return diem; }
};  

int main() {
    SinhVien s;
    cin >> s;
    cout << s;
    return 0;
}
