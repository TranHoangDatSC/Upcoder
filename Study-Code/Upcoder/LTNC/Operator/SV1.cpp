#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct SinhVien
{
    string HoTen;
    vector<float> Diem;
};

istream& operator >> (istream& is, SinhVien& a)
{
    getline(is, a.HoTen);
    float tmp;
    for(int i=0;i<3;i++)
    {
        is >> tmp;
        a.Diem.push_back(tmp); // them vao vector
    }
    return is;
}

ostream& operator << (ostream& os, SinhVien a)
{
    os << a.HoTen;
    return os;
}

float DTB(vector<float>Diem)
{
    float sum = 0.0;
    for(int i=0;i<Diem.size();i++)
    {
        sum+=Diem[i];
    }
    return sum/Diem.size();
}
int main()
{
    vector<SinhVien> Container;
    SinhVien tmp;
    while(cin>>tmp)
    {
        Container.push_back(tmp);
        cin.ignore();
    }
    
    int j=0;
    float DTBtmp = DTB(Container[0].Diem);
    for(int i=1;i<Container.size();i++)
    {
        if(DTBtmp < DTB(Container[i].Diem))
        {
            DTBtmp = DTB(Container[i].Diem);
            j=i;
        }
    }
    cout << Container[j];
    return 0;
}
