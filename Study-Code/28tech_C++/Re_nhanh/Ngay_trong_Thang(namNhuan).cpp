#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int m, y;
    cin >> m >> y;
    
    switch(m)
    {
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12:
        {
            cout << 31;
            break;
        }
        case 4 : case 6 : case 9 : case 11:
        {
            cout << 30;
            break;
        }
        case 2:
        {
            if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            {
                cout << 29;
                break;
            }
            else 
            {
                cout << 28;
                break;
            }
        }
    }
    return 0;
}
