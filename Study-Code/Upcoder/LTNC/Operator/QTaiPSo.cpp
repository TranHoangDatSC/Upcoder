#include <iostream>


class PhanSo 
{
    private:
        int Tu, Mau;
    public:
        friend std::istream& operator >> (std::istream& in, PhanSo& p)
        {
            in >> p.Tu >> p.Mau;
            return in;
        }
        int gettu()
        {
                return this -> Tu;
        }  
        int getmau()
        {
                return this -> Mau;
        }  
        friend std::ostream& operator << (std::ostream& out, PhanSo p)
        {
            out << p.Tu << "/" << p.Mau;
            return out;
        }
        PhanSo operator + (PhanSo another) 
        {
            PhanSo Tong;
            Tong.Tu = this -> Tu * another.Mau + another.Tu * this -> Mau;
            Tong.Mau = this -> Mau * another.Mau;
            return Tong;
        }
        bool operator == (PhanSo another)
        {
            return (this -> Tu / this -> Mau == another.Tu / another.Mau);
        }
        bool operator != (PhanSo another)
        {
            return (this -> Tu / this -> Mau != another.Tu / another.Mau);
        }
        int FindGCD(int a, int b);
        void compact();
};

int PhanSo::FindGCD(int a, int b)
{
    if (b == 0)
        return a;
    return FindGCD(b, a % b);
}

void PhanSo::compact()
{
    int gcd = FindGCD(this->Tu, this->Mau);
    this->Tu /= gcd;
    this->Mau /= gcd;
}
int main()
{
    PhanSo a,b,Tong;
    std::cin >> a >> b;
    Tong = a + b;
    Tong.compact();
    std::cout << Tong;
    return 0;
}
