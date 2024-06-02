#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int year = n/365;
    int square = n%365;
    
    int week = square / 7;
    int day = square % 7;
    
    cout << year << " " << week << " " << day;
        
    return 0;
}
