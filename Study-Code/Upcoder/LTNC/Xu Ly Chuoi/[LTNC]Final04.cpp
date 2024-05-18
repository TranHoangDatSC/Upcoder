#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool hopLe(string SDT)
{
    if(SDT.size() != 10)  return false;
    
    for(char c : SDT)
    {
        if(!isdigit(c)) return false;
    }
    return true;
}

string thongTin(string SDT)
{
    if(!hopLe(SDT)) return "Khong hop le";
    
    string maTinh[] = {"04","08","059","061","0511","0710"};
    string tenTinh[] = {"Ha Noi", "TPHCM", "Gia Lai", "Dong Nai", "Da Nang", "Can Tho"};
    
    int pos;
    
    for(int i = 0; i < 6; i++)
    {
        pos = SDT.substr(0,4).find(maTinh[i]);
        if(pos != string::npos)
            return tenTinh[i] + " - " + SDT.substr(maTinh[i].size());
    }
}

int main()
{
    string str;
    getline(cin,str);
    cout << thongTin(str);
    return 0;
}
