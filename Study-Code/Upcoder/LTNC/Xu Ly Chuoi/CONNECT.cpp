#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream ifile ("CONNECT.INP");
    ofstream ofile ("CONNECT.OUT");
    
    vector<int> vt;
    string res = "";
    
    int size;
    ifile >> size;
    
    while(size--)
    {
        int n;
        ifile >> n;
        vt.push_back(n);
    }
    
    sort(vt.begin(), vt.end(), [](int a,int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    
    for(int x : vt)
    {
        res += to_string(x);
    }
    ofile << res;
    
    ifile.close();
    ofile.close();
    return 0;
}
