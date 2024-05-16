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
    bool operator < (int other)
    {
        return this->mp[this->laMa] < other;
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

template<typename T>
struct Mang
{
    int size = -1;
    T values[100];
    
    void operator = (Mang arr)
    {
        size = arr.size;
        for(int i = 0; i < size; i++)
        {
            values[i] = arr.values[i];
        }
    }
    T& operator [](int index)
    {
        return values[index];
    }
    
    friend istream& operator >> (istream& is, Mang<T>& arr)
    {
        is >> arr.values[++arr.size];
        return is;
    }
    
    friend ostream& operator << (ostream& os, Mang<T> arr)
    {
        os << arr.minNum() << "\n" << arr.sum() << "\n";
        return os;
    }
    
    int sum()
    {
        int res = values[0] + 0;
        for(int i = 1; i <= size; i++)
        {
            res = values[i] + res;
        }
        return res;
    }
    int minNum()
    {
        int res = values[0] + 0;
        for(int i = 0; i <= size; i++)
        {
            if(values[i] < res)
                res = values[i] + 0;
        }
        return res;
    }
    bool empty()
    {
        return size == -1;
    }
};

int main()
{
    Mang<int> a;
    Mang<SoLaMa> b;
    
    char type;
    
    while(cin >> type)
    {
        if(type == 'N') cin >> a;
        else cin >> b;
    }
    
    if(a.empty()) cout << "khong co\nkhong co\n";
    else cout << a;
    
    if(b.empty()) cout << "khong co\nkhong co\n";
    else cout << b;
    
    return 0;
}
