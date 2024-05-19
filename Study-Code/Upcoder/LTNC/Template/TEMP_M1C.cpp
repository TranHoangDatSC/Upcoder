#include <iostream>
using namespace std;

template<typename T>
struct M1C
{
    int size;
    T values[100];
    
    void nhap()
    {
        size=0;
        T x;
        while(cin>>x)
        {
            values[size++]=x;
        }
    }
    void xuat()
    {
        T x;
        for(int i=0;i<size;i++)
        {
            cout << x[i] << " ";
        }
    }
    int tong()
    {
        int sum = 0;
        for(int i=0;i<size;i++)
        {
            sum = sum + values[i];
        }
        return sum;
    }
};

int main()
{
    M1C<int> a;
    a.nhap();
    cout << a.tong();
    return 0;
}
