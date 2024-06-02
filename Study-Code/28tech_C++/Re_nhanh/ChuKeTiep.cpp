#include <iostream>
#include <string>
using namespace std;

// Viet chuong trinh viet ra chu cai tiep theo trong bang chu cai
// Neu den "z" or "Z", quay lai "a" or "A" la ke tiep

int main()
{
    char a;
    cin >> a;
    
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
    {
        if(a == 'z' || a == 'Z')
            cout << "a";
    
        else 
        {
            if(a == 'z' || a == 'Z')
                a += 32;
            
            ++a;
            cout << a;
        }
    }
    else
        cout << "INVALID";
    
    return 0;
}
