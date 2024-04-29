#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct ThongTin
{
    int stt;
    string name;
    string mssv;
    
    ThongTin() {}
    ThongTin(string tmp) 
    {
        stringstream ss(tmp);
        vector<string> str;
        
        while(ss >> tmp)
        {
            str.push_back(tmp);
        }
        
        stt = stoi(str.front());
        str.erase(str.begin());
        
        mssv = str.back();
        str.pop_back();
        
        for(string x : str)
        {
            name += x + " ";
        }
    }
    friend ostream& operator << (ostream& os, ThongTin sv)
    {
        os << "STT: " << sv.stt << "\n";
        os << "Ho va ten: " << sv.name << "\n";
        os << "MSSV: " << sv.mssv << "\n";
        return os;
    }
};

int main()
{
    vector<ThongTin> list;
    string tmp;
    
    while(getline(cin,tmp))
    {
        list.push_back(ThongTin(tmp));
    }
    sort(list.begin(), list.end(), [] (ThongTin a, ThongTin b)
    {
        return a.stt < b.stt;
    });
    
    for(auto x : list)
    {
        cout << x << "\n";
    }
    return 0;
}
