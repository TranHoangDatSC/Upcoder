#include <iostream>
using namespace std;

void input(int arr[],int n);
void output(int arr[],int n);

void bubble_sort(int arr[], int n);
// Thuật toán sắp xếp nổi bọt, tr/hợp: Bé -> Lớn

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    input(arr,n);
    
    bubble_sort(arr,n);

    output(arr,n);
    
    return 0;
}

void input(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void output(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1]) // Đổi thành "<" nếu muốn xếp số lớn nhất trước
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/*
#include <iostream>
using namespace std;

struct Diem {
    int diem;  
    
    friend istream& operator >> (istream& is, Diem& d) {
        is >> d.diem;
        return is;
    }
    
    friend ostream& operator << (ostream& os, Diem d) {
        cout << d.diem;
        return os;
    }
    
    bool operator < (Diem other) {
        return this->diem < other.diem;
    }
};

void swap(Diem &a,Diem &b) {
    Diem tmp = a;
    a = b;
    b = tmp;
}

template <class Diem>
void bubble_sort(Diem a[],int n) {
    int i,j;
    
    for(i = 0; i < n - 1; i++) {
        for(j = n - 1; j > i; j--) {
            if(a[j] < a[j-1])
                swap(a[j],a[j-1]);
        }
    }
}

int main() {
    Diem a[100];
    int n = 0;
    
    while(cin >> a[n]) n++;
    
    bubble_sort(a,n);
    
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
    
    return 0;
}
*/
