#include <iostream>
#include <iomanip>
using namespace std;

struct SinhVien
{
    char* hoTen;
    int namSinh;
    float diem[3];
    
};

void inputList(SinhVien list[] , int n)
{
    for(int i = 0; i < n; i++)
    {
        list[i].hoTen = new char[50];
        cin.getline(list[i].hoTen,50);
        
        cin >> list[i].namSinh;
        cin >> list[i].diem[0] >> list[i].diem[1] >> list[i].diem[2];
        
        cin.ignore();
    }
}

double diemTB(float list[])
{
    double res = 0;
    for(int i = 0; i < 3; i++)
    {
        res += list[i];
    }
    return res/3;
}

void sapXepGiam(SinhVien list[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(diemTB(list[i].diem) < diemTB(list[j].diem))
                swap(list[i], list[j]);
        }
    }
}

void outputList(SinhVien list[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << " - ";
        cout << list[i].hoTen << " - ";
        cout << list[i].namSinh << " - ";
        cout << setprecision(2) << fixed << diemTB(list[i].diem) << "\n";  
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    SinhVien list[n];
    inputList(list, n);
    sapXepGiam(list, n);
    outputList(list, n);
    
    for(int i = 0; i < n; i++)
    {
        delete[] list[i].hoTen;
    }
    return 0;
}

/*
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
*/
