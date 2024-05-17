#include <iostream>
#include <cmath>
using namespace std;

const double EPSILON = 1e-9;

struct Diem
{
    int x, y;
    
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
    
    double Range(Diem other)
    {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
    }
};

bool checkTG(double AB, double BC, double CA)
{
    return AB + BC > CA && AB + CA > BC && BC + CA > AB;
}

bool tamgiacVuong(double AB, double BC, double CA)
{
    return (abs(pow(AB,2) + pow(BC,2) - pow(CA,2)) < EPSILON) 
    || (abs(pow(BC,2) + pow(CA,2) - pow(AB,2))  < EPSILON)
    || (abs(pow(AB,2) + pow(CA,2) - pow(BC,2)) < EPSILON);
}

char gocVuong(double AB, double BC, double CA)
{
    if(abs(pow(AB,2) + pow(BC,2) - pow(CA,2)) < EPSILON) return 'B';
    else if(abs(pow(BC,2) + pow(CA,2) - pow(AB,2)) < EPSILON) return 'C';
    else if(abs(pow(AB,2) + pow(CA,2) - pow(BC,2)) < EPSILON) return 'A';
}

int main()
{
    Diem A,B,C;
    double AB,BC,CA;
    
    cin >> A >> B >> C;
    
    AB = A.Range(B);
    BC = B.Range(C);
    CA = C.Range(A);
    
    cout << A << "," << B << "," << C << "\n";
    
    if(checkTG(AB,BC,CA))
    {
        cout << "CO\n";
        if(tamgiacVuong(AB,BC,CA))
            cout << gocVuong(AB,BC,CA);
    }
    
    else cout << "KHONG";
    return 0;
}
