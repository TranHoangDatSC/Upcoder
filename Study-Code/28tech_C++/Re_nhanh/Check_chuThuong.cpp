#include <iostream>
#include <string>
using namespace std;

int main()
{
    char a;
    cin >> a;
    
    if(a >= 97 && a <= 122)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char a;
    cin >> a;
    
    if(a >= 'a' && a <= 'z')
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
*/
