#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int daoNguoc(string str)
{
    int res = 0;
    for(int i = str.size() - 1; i >= 0; i--)
    {
        if(str[i] == '-')   
            res = -res;
        else 
            res = res * 10 + (str[i] - '0') % 10;
    }
    return res;
}
int main()
{
    string max = "-10000";
    string chuSo;
    int cnt = 0;
    vector<int> pos;
    
    ifstream ifile("inDaoNguoc2.txt");
    while(ifile >> chuSo)
    {
        if(daoNguoc(chuSo) > daoNguoc(max))
        {
            max = chuSo;
            pos.clear();
            pos.push_back(cnt);
        }
        else if(daoNguoc(max) == daoNguoc(chuSo))
        {
            pos.push_back(cnt);
        }
        cnt++;
    }
    ifile.close();
    
    ofstream ofile("outDaoNguoc2.txt");
    ofile << max << '\n';
    
    if(pos.size() > 1)
    {
        for(int n : pos)
            ofile << n << " ";
    }
    ofile.close();
    
    return 0;
}
