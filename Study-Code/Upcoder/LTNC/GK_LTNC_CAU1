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
