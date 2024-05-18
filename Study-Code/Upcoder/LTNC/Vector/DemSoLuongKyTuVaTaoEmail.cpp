#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <fstream>
#include <algorithm>
using namespace std;

string taoTen(string str)
{
    string token, res("");
    stringstream ss(str);
    vector<string> v;
    
    while(ss >> token)
    {
        v.push_back(token);
    }
    
    res = v.back();
    v.pop_back();
    
    for(string x : v)
    {
        res += x[0];
    }
    return res;
}

int main()
{
    ifstream ifile("input.txt");
    ofstream ofile("output.txt");
    
    char c;
    int nguoibiTrung = 0;
    
    string str;
    vector<string> hoTen, Ten, gmail;
    
    ifile >> c;
    ifile.ignore();
    
    while(getline(ifile,str))
    {
        for(char &s : str)
            s = tolower(s);
            
        hoTen.push_back(str);
    }
    
    for(string s : hoTen)
    {
        string res, tmp = taoTen(s);
        
        int kyTuTrung = count(s.begin(), s.end(), tolower(c));
        int soLuong = count(Ten.begin(), Ten.end(), tmp);
        
        res = to_string(kyTuTrung) + "-" + tmp;
        if(soLuong == 0)
            res += "@gmail.com";
            
        else 
        {
            nguoibiTrung += soLuong == 1 ? 2 : 1;
            res += to_string(soLuong+1) + "@gmail.com";
        }
        
        gmail.push_back(res);
        Ten.push_back(tmp);
    }
    
    for(string s : gmail)
    {
        ofile << s << '\n';
    }
    ofile << nguoibiTrung;
    
    
    ifile.close();
    ofile.close();
    return 0;
}
