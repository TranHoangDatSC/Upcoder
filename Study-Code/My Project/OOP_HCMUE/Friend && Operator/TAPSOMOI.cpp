#include <iostream>
using namespace std;

class TapSoMoi
{
    private:
        int x,y,z,t;
        
    public:
        TapSoMoi()
        {
            x = 0;
            y = 0;
            z = 0;
            t = 0;
        }
        TapSoMoi(int a,int b,int c,int d)
        {
            x = a;
            y = b;
            z = c;
            t = d;
        }
        friend istream& operator >> (istream& is, TapSoMoi& sm)
        {
            is >> sm.x >> sm.y >> sm.z >> sm.t;
            return is;
        }
        friend ostream& operator << (ostream& os, TapSoMoi sm)
        {
            os << "[TapSoMoi] " << sm.x << ";" << sm.y << ";"
            << sm.z << ";" << sm.t << "\n";
            return os;
        }
        
        TapSoMoi operator + (TapSoMoi other)
        {
            TapSoMoi kq;
            kq.x = this->x + other.x;
            kq.y = this->y + other.y;
            kq.z = this->z + other.z;
            kq.t = this->t + other.t;
            return kq;
        }
        int sum()
        {
            int kq = this->x + this->y + this->z + this->t;
            return kq;
        }
        bool operator < (TapSoMoi other)
        {
            return this->sum() < other.sum();
        }
        void operator = (TapSoMoi other)
        {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            this->t = other.t;
        }
        TapSoMoi operator ++ (int)
        {
            TapSoMoi kq = *this;
            ++(*this );
            return kq;
            
        }
        TapSoMoi& operator ++ ()
        {
            this->x = this->x + 1;
            this->t = this->t + 1;
            return *this;
        }
        
        static void nhap(TapSoMoi tsm[], int& cnt)
        {
            while(cin >> tsm[cnt])
                cnt++;
        }
        static void xuat(TapSoMoi tsm[], int cnt)
        {
            for(int i = 0; i < cnt; i++)
            cout << tsm[i];
        
            cout << (tsm[0] < tsm[1] ? "true\n" : "false\n");
            cout << tsm[0] + tsm[1];
            cout << ++tsm[0];
        }
};

int main()
{
    TapSoMoi tsm[10];
    int cnt = 0;
    
    TapSoMoi::nhap(tsm,cnt);
    TapSoMoi::xuat(tsm,cnt);
    
    return 0;
}
