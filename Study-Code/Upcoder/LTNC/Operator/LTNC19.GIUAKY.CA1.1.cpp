#include <iostream>
#include <map>
using namespace std;

struct SoLaMa
{
    string laMa;
    map<string, int> mp = {{"I", 1} , {"II",2} , {"III",3} , {"IV",4} , {"V",5} ,
    {"VI",6} , {"VII",7} , {"VIII",8} , {"IX",9} , {"X",10}};
    
    friend istream& operator >> (istream& is, SoLaMa& so)
    {
        is >> so.laMa;
        return is;
    }
    friend ostream& operator << (ostream& os, SoLaMa so)
    {
        os << so.mp[so.laMa];
        return os;
    }
    bool operator < (SoLaMa other)
    {
        return this->mp[this->laMa] < other.mp[other.laMa];
    }
    int operator + (SoLaMa other)
    {
        return this->mp[this->laMa] + other.mp[other.laMa];
    }
    int operator + (int other)
    {
        return this->mp[this->laMa] + other;
    }
};

int main()
{
    SoLaMa a,b;
    cin >> a >> b;
    cout << a << "\n" << b << "\n" <<a + b << "\n" << (a < b ? "true" : "false");
    return 0;
}
