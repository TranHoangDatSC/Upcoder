#include <iostream>
#include <map>
using namespace std;

struct soLaMa
{
    string laMa;
    map<string, int> mp = { {"I",1} , {"II",2} , {"III",3} , {"IV",4} 
    , {"V",5} , {"VI",6} , {"VII",7} , {"VIII",8} , {"XI",9} , {"X",10} };
    
    friend istream& operator >> (istream& is, soLaMa& so)
    {
        is >> so.laMa;
        return is;
    }
    friend ostream& operator << (ostream& os, soLaMa so)
    {
        os << so.mp[so.laMa];
        return os;
    }
    
    bool operator < (soLaMa other)
    {
        return this->mp[laMa] < other.mp[other.laMa];
    }
    bool operator > (int other)
    {
        return this->mp[laMa] > other;
    }
    int operator + (soLaMa other)
    {
        return this->mp[laMa] + other.mp[other.laMa];
    }
    int operator + (int other)
    {
        return this->mp[laMa] + other;
    }
};

template<typename T>
struct Mang
{
    int size;
    T values[100];
    
    T& operator[](int index)
    {
        return values[index];
    }
    
    void operator = (Mang arr)
    {
        size = arr.size;
        for(int i = 0; i < size; i++)
        {
            values[i] = arr.values[i];
        }
    }
    
    int sum()
    {
        int res = 0;
        for(int i = 0; i < size; i++)
        {
            res = values[i] + res;
        }
        return res;
    }
    int maxNum()
    {
        int res = values[0] + 0;
        for(int i = 1; i < size; i++)
        {
            if(values[i] > res)
                res = values[i] + 0;
        }
        return res;
    }
    
    void run()
    {
        size = 0;
        while(cin >> values[size])
        {
            size++;
        }
        cout << maxNum() << "\n" << sum() << "\n"; 
    }
    
};

template<typename T>
void check()
{
    Mang<T> arr;
    arr.run();
}

int main()
{
    Mang<int> N;
    Mang<soLaMa> L;
    
    char type;
    cin >> type;
    
    switch(type)
    {
        case 'N':
        {
            check<int>();
            break;
        }
        case 'L':
        {
            check<soLaMa>();
            break;
        }
    }
    return 0;
}
