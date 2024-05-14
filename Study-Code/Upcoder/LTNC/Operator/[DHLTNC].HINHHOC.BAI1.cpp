#include <iostream>
#include <cmath>
using namespace std;

struct toaDo
{
    int x,y;
    friend istream& operator >> (istream& is, toaDo& td)
    {
        is >> td.x >> td.y;
        return is;
    }
};
double Range(toaDo td1, toaDo td2)
{
    return sqrt(pow(td2.x - td1.x, 2) + pow(td2.y - td1.y, 2));
}
bool check(double d1, double d2, double d3)
{
    return (d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1);
}
int main()
{
    toaDo a,b,c;
    cin >> a >> b >> c;
    
    double d1 = Range(a,b);
    double d2 = Range(a,c);
    double d3 = Range(b,c);
    
    cout << ((check(d1,d2,d3) == true) ? "YES" : "NO");
    
    return 0;
}
