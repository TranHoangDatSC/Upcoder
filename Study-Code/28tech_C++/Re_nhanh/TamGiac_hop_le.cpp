#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b)
        cout << "YES";
    else 
        cout << "NO";
        
    return 0;
}
