#include <iostream>
#include <algorithm>
using namespace std;

struct Diem
{
    int x,y;
    
    friend istream& operator >> (istream& is, Diem& d)
    {
        is >> d.x >> d.y;
        return is;
    }
    friend ostream& operator << (ostream& os, Diem d)
    {
        os << "(" << d.x << "," << d.y << ")";
        return os;
    }
    
    bool operator == (Diem other)
    {
        return this->x == other.x && this->y == other.y;
    }
    
    bool operator < (Diem other)
    {
        if(this->x < other.x) return true;
        else if(this->x == other.x && this->y < other.y) return true;
        else return false;
    }
    
    Diem operator + (Diem other)
    {
        Diem kq;
        kq.x = this->x + other.x;
        kq.y = this->y + other.y;
        return kq;
    }
};

struct Array
{
    int size;
    Array()
    {
        size = 0;
    }
    Diem values[100];
    
    void operator = (Array arr)
    {
        size = arr.size;
        for(int i = 0; i < arr.size; i++)
        {
            values[i] = arr.values[i];
        }
    }
    
    Diem& operator [](int index)
    {
        return values[index];
    }
    
    friend istream& operator >> (istream& is, Array& arr)
    {
        arr.size = 0;
        while(is >> arr.values[arr.size])
        {
            arr.size++;
        }
        return is;
    }
    friend ostream& operator << (ostream& os, Array arr)
    {
        Diem Max = arr.values[0], Sum = arr.values[0];
        for(int i = 1 ; i < arr.size; i++)
        {
            if(Max < arr.values[i]) 
                Max = arr.values[i];
            
            Sum = Sum + arr.values[i];
        }
        os << Max << "\n" << Sum;
        return os;
    }
    
    Array operator + (Array other)
    {
        Array res;
        res.size = max(this->size, other.size);
        
        for(int i = 0; i < res.size; i++)
        {
            if(i < this->size && i < other.size)
                res.values[i] = this->values[i] + other.values[i];
            else if(i < this->size)
                res.values[i] = this->values[i];
            else if(i < other.size)
                res.values[i] = other.values[i];
        }
        return res;
    }
};
    
int main()
{
    Array arr;
    cin >> arr;
    cout << arr;
    return 0;
}
