#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    int max = a;
    
    if(b > max) max = b;
    if(c > max) max = c;
    
    int min = c;
    
    if(a < min) min = a;
    if(b < min) min = b;
    
    cout << max << " " << min;
    
    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    int max, min;
    
    if(a > b && a > c)
        max = a;
    else if(b > a && b > c)
        max = b;
    else if(c > a && c > b)
        max = c;
        
    if(a < b && a < c)
        min = a;
    else if(b < a && b < c)
        min = b;
    else if(c < a && c < b)
        min = c;
        
    cout << max << " " << min;
    
    return 0;
}
*/
