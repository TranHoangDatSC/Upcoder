#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void select_sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
       int min_idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    int n(0);
    int arr[100];
    
    while(cin >> arr[n])
        n++;
        
    select_sort(arr,n);
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
        
    return 0;
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
void selection_sort(Diem a[],int n) {
    int min;
    
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min]) min = j;
        }
        if(min != i)
            swap(a[min],a[i]);
    }
}

int main() {
    Diem a[100];
    int n = 0;
    
    while(cin >> a[n]) n++;
    
    selection_sort(a,n);
    
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
    
    return 0;
}
*/
