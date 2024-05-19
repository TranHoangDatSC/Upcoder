#include <iostream>
#include <cmath>
using namespace std;

struct SoPhuc 
{
    int thuc,ao;  
    
    friend istream& operator >> (istream& is, SoPhuc& p)
    {
        is >> p.thuc >> p.ao;
        return is;
    }
    friend ostream& operator << (ostream& os, SoPhuc p)
    {
        if (p.thuc != 0) os << p.thuc;
        
        if (p.ao != 0)
        {
            if(p.thuc!=0 && p.ao < 0) 
                os << "-";
            if(p.ao > 0)
                os << "+";
             
            os << abs(p.ao) << "*i";
        }
        
        if (p.thuc == 0 && p.ao == 0)
            os << 0;
        return os;
    }
    
    SoPhuc operator + (SoPhuc other)
    {
        SoPhuc result;
        result.thuc = this->thuc + other.thuc;
        result.ao = this->ao + other.ao;
        return result;
    }
    SoPhuc operator - (SoPhuc other)
    {
        SoPhuc result;
        result.thuc = this->thuc - other.thuc;
        result.ao = this->ao - other.ao;
        return result;
    }
    SoPhuc operator * (SoPhuc other)
    {
        SoPhuc result;
        result.thuc = this->thuc * other.thuc - this->ao * other.ao;
        result.ao = this->thuc * other.ao + this->ao * other.thuc;
        return result;
    }
    bool operator < (SoPhuc other)
    {
        if(this->thuc < other.thuc) 
            return true;
        else if (this->thuc == other.thuc)
            if (this-> ao < other.ao) return true;
        return false;
    }
};


int main()
{
    int size,length=0;
    cin >> size;
    SoPhuc x;
    SoPhuc a[10];
    while (cin>>x)
    {
        a[length++]=x;
    }
    SoPhuc max = a[0];
    SoPhuc min = a[0];
    SoPhuc sum = a[0];
    SoPhuc multip = a[0];
    for(int i=1;i<size;i++)
    {
        if(max<a[i])
            max = a[i];
        if(a[i]<min)
            min = a[i];
        sum = sum + a[i];
        multip = multip * a[i];
    }
    cout << max << "\n";
    cout << sum << "\n" << multip << "\n";
    cout << max - min;
    return 0;
}
