#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b)
    {
        if(a == b && b == c && c == a)
        {
            cout << "Tam giac deu";
        }
        else if(a == b || a == c || b == c)
        {
            if(a*a == b*b + c*c || b*b == c*c + a*a || c*c == b*b + a*a)
                cout << "Tam giac vuong can";
                
            else 
                cout << "Tam giac can";
        }
        
        else if(a*a == b*b + c*c || b*b == c*c + a*a || c*c == b*b + a*a)
        {
            cout << "Tam giac vuong";
        }
        
        else 
        {
            cout << "Tam giac thuong";
        }
    }
        
    else 
    {   
        cout << "INVALID";
    }
        
    return 0;
}
