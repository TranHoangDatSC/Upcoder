#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    switch(n)
    {
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
            cout << "Thang " << n << " co 31 ngay";
            break;
            
        case 4 : case 6 : case 9 : case 11 :
            cout << "Thang " << n << " co 30 ngay";
            break;
        case 2 :
            cout << "Thang " << n << " co 28 hoac 29 ngay";
            break;
            
        default : cout << "Khong hop le";
    }
    return 0;
}
