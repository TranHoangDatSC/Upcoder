#include <iostream>
using namespace std;

class TapSoMoi
{
    private:
        int x,y,z,t;
        
    public: 
    
        // 2 Constructor
        TapSoMoi()
        {
            x = 0; y = 0; z = 0; t = 0;
        }
        TapSoMoi(int _x,int _y,int _z,int _t)
        {
            x = _x;
            y = _y;
            z = _z;
            t = _t;
        }
        
        // 2 operator >> and <<
        friend istream& operator >> (istream& is,TapSoMoi& tsm)
        {
            is >> tsm.x >> tsm.y >> tsm.z >> tsm.t;
            return is;
        }
        friend ostream& operator << (ostream& os, TapSoMoi tsm)
        {
            os << "[TapSoMoi] " << tsm.x << ";" << tsm.y << ";" << tsm.z << ";" << tsm.t << "\n";
            return os;
        }
        
        // All Object TapSoMoi Method
        int TongThanhVien() 
        {
            int sum = x + y + z + t;
            return sum;
        }
        
        // Operator < TongThanhVien
        bool operator < (TapSoMoi other)
        {
            return this->TongThanhVien() < other.TongThanhVien();
        }
        
        // Operator + TapSoMoi
        TapSoMoi operator + (TapSoMoi other)
        {
            TapSoMoi kq;
            kq.x = this->x + other.x;
            kq.y = this->y + other.y;
            kq.z = this->z + other.z;
            kq.t = this->t + other.t;
            return kq;
        }
        
        // Operator = 
        void operator = (TapSoMoi other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            t = other.t;
        }
        
        // Operator ++
        TapSoMoi& operator ++ ()
        {
            this->x = this->x + 1;
            this->t = this->t + 1;
            return *this;
        }
        TapSoMoi operator ++ (int)
        {
            TapSoMoi kq = *this;
            ++ (*this);
            return kq;
        }
}

int main()
{
    TapSoMoi a,b;
    cin >> a >> b;
    cout << a << b;
    cout << ((a < b) ? "true" : "false") << "\n";
    cout << a + b;
    a++;
    cout << a;
    return 0;
}
