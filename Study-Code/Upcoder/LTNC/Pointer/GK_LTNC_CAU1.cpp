#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <cstring>
using namespace std;

struct SinhVien
{
    char* hoTen;
    int namSinh;
    float diem[3];
    
    float diemTB()
    {
        return (diem[0] + diem[1] + diem[2]) / 3;
    }
    
    friend istream& operator >> (istream& is, SinhVien& sv)
    {
        sv.hoTen = new char[100];
        is.ignore();
        
        fgets(sv.hoTen, 100, stdin);
        sv.hoTen[strcspn(sv.hoTen,"\n")] = ' ';
        
        is >> sv.namSinh;
        for(int i = 0; i < 3; i++)
        {
            is >> sv.diem[i];
        }
        return is;
    }
    
    friend ostream& operator << (ostream& os, SinhVien sv)
    {
        os << fixed << setprecision(2);
        os << sv.hoTen << " - " << sv.namSinh << " - " << sv.diemTB();
        return os;
    }
};

void inList(SinhVien *list, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
}

void sortGiamDan(SinhVien *list, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(list[i].diemTB() < list[j].diemTB())
                swap(list[i],list[j]);
        }
    }
}

void outList(SinhVien *list, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << " - " << list[i] << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    SinhVien *list = new SinhVien[n];
    
    inList(list,n);
    sortGiamDan(list,n);
    outList(list,n);
    
    delete[] list;
    return 0;
}
