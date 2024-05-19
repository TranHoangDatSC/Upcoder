#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct KG2C
{
    int x, y;

    friend istream& operator >> (istream& is, KG2C& k)
    {
        is >> k.x >> k.y;
        return is;
    }
    friend ostream& operator << (ostream& os, KG2C k)
    {
        os << "(" << k.x << "," << k.y << ")";
        return os;
    }

    double operator - (KG2C k)
    {
        return sqrt(pow(this->x - k.x, 2) + pow(this->y - k.y, 2));
    }
    bool operator < (KG2C k)
    {
        if (this->x < k.x) return true;
        if (this->x == k.x && this->y < k.y) return true;
        return false;
    }
};

struct KG3C
{
    int x, y, z;

    friend istream& operator >> (istream& is, KG3C& k)
    {
        is >> k.x >> k.y >> k.z;
        return is;
    }
    friend ostream& operator << (ostream& os, KG3C k)
    {
        os << "(" << k.x << "," << k.y << "," << k.z << ")";
        return os;
    }
    double operator - (KG3C k)
    {
        return sqrt(pow(this->x - k.x, 2) + pow(this->y - k.y, 2) + pow(this->z - k.z, 2));
    }
    bool operator < (KG3C k)
    {
        if (this->x < k.x) return true;
        if (this->x == k.x && this->y < k.y) return true;
        if (this->x == k.x && this->y == k.y && this->z < k.z) return true;
        return false;
    }
};

template<typename T>
struct Diem
{
    int size;
    T values[100];

    Diem() : size(0) {}

    void operator = (Diem p)
    {
        size = p.size;
        for (int i = 0; i < size; i++)
        {
            values[i] = p.values[i];
        }
    }
    T& operator [](int index)
    {
        return values[index];
    }

    friend istream& operator >> (istream& is, Diem& d)
    {
        T n;
        cin >> n;
        d.values[d.size++] = n;
        return is;
    }
    friend ostream& operator << (ostream& os, Diem d)
    {
        for (int i = 0; i < d.size; i++)
        {
            os << d.values[i] << " ";
        }
        return os;
    }

    double maxRange()
    {
        double result = 0;
        for (int i = 0; i < this->size; i++)
        {
            for (int j = i + 1; j < this->size; j++)
            {
                if (result < (this->values[i] - this->values[j]))
                    result = this->values[i] - this->values[j];
            }
        }
        return result;
    }

    void sortMax()
    {
        for (int i = 1; i < this->size; i++)
        {
            int j = i;
            while (j > 0 && this->values[j] < this->values[j - 1])
            {
                swap(this->values[j], this->values[j - 1]);
                j--;
            }
        }
    }
    void sortMin()
    {
        for (int i = 1; i < this->size; i++)
        {
            int j = i;
            while (j > 0 && this->values[j - 1] < this->values[j])
            {
                swap(this->values[j - 1], this->values[j]);
                j--;
            }
        }
    }
};

int main()
{
    string type;
    Diem<KG2C> arr1;
    Diem<KG3C> arr2;

    while (cin >> type)
    {
        if (type == "Oxy")
            cin >> arr1;
        else if (type == "Oxyz")
            cin >> arr2;
    }

    arr1.sortMax();
    cout << arr1 << "\n";
    arr2.sortMin();
    cout << arr2 << "\n";

    cout << roundf(arr1.maxRange() * 1000) / 1000 << "\n";
    cout << roundf(arr2.maxRange() * 1000) / 1000;
    return 0;
}
