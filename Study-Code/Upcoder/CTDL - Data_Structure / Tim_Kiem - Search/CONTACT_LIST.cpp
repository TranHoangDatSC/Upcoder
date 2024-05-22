#include <iostream>
using namespace std;

struct PhoneList
{
    string sdt;
    int to, back;
    
    friend istream& operator >> (istream& is, PhoneList& pl)
    {
        is >> pl.sdt >> pl.to >> pl.back;
        return is;
    }
    
    friend ostream& operator << (ostream& os, PhoneList pl)
    {
        os << "{" << pl.sdt << "," << pl.to << "," << pl.back << "}\n";
        return os;
    }
};

int main()
{
    string target;
    int n;
    cin >> n >> target;
    
    PhoneList arr[n];
    
    for(int i = 0; i  < n; i++)
    {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i].sdt == target)
            cout << arr[i];
    }
    
    int max_to = -10e6;
    PhoneList save_max_to;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].to > max_to)
        {
            max_to = arr[i].to;
            save_max_to = arr[i];
        }
    }
    cout << save_max_to;
    
    int min_back = 100;
    PhoneList save_min_back;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].back < min_back)
        {
            min_back = arr[i].back;
            save_min_back = arr[i];
        }
    }
    cout << save_min_back;
    
    return 0;
}
