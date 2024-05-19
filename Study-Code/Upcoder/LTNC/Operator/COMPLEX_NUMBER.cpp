#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct SoPhuc
{
    int thuc,ao;
    
    friend istream& operator >> (istream& is, SoPhuc& sp)
    {
        is >> sp.thuc >> sp.ao;
        return is;
    }
    
    friend ostream& operator << (ostream& os, SoPhuc sp)
    {
        os << "{";
        if(sp.thuc!=0) os << sp.thuc;
        
        if(sp.ao!=0)
        {
            if(sp.thuc!=0 && sp.ao > 0) os << "+";
            if(sp.thuc!=0 && sp.ao < 0) os << "-";
            if(sp.thuc==0 && sp.ao > 0) os << "";
            if(sp.thuc==0 && sp.ao < 0) os << "-";
            if(abs(sp.ao)!=1) os << abs(sp.ao);
            
            os << "i";
        }
        
        if(sp.thuc==0 && sp.ao==0) os << "0";
        
        os << "}";
        
        return os;
    }
    
    SoPhuc operator + (SoPhuc sp)
    {
        SoPhuc kq;
        kq.thuc = this->thuc + sp.thuc;
        kq.ao = this->ao + sp.ao;
        return kq;
    }
    SoPhuc operator - (SoPhuc sp)
    {
        SoPhuc kq;
        kq.thuc = this->thuc - sp.thuc;
        kq.ao = this->ao - sp.thuc;
        return kq;
    }
    
    double modun() 
    {
        return sqrt(pow(this->thuc,2) + pow(this->ao,2));
    }
};

struct Mang
{
    int size;
    SoPhuc *values;
    
    friend istream& operator >> (istream& is, Mang& m)
    {
        m.size = 0;
        m.values = new SoPhuc[100];
        while(is>>m.values[m.size])
        {
            m.size++;
        }
        return is;
    }
    friend ostream& operator << (ostream& os, Mang m)
    {
        for(int i=0;i<m.size;i++)
        {
            os << *(m.values + i) << " ";
        }
        os << "\n";
        return os;
    }
    void tinhModun()
    {
        cout << setprecision(2) << fixed; 
        for(int i=0;i<this->size;i++)
        {
            cout << this->values[i].modun() << " ";
        }
    }
    SoPhuc tinhTong()
    {
        SoPhuc kq = *(this->values);
        for(int i=1;i<this->size;i++)
        {
            kq = kq + *(this->values + i);
        }
        return kq;
    }
    SoPhuc tinhHieu()
    {
        SoPhuc kq = *(this->values);
        for(int i=1;i<this->size;i++)
        {
            kq = kq - *(this->values + i);
        }
        return kq;
    }
};

int main()
{
    Mang a;
    cin >> a;
    cout << a;
    a.tinhModun();
    cout << "\n" << a.tinhTong();
    return 0;
}
