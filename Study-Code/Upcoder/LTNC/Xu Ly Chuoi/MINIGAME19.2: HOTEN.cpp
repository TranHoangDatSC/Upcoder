#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    
    stringstream ss(str);
    string tmp;
    vector<string> vt;
    while(ss >> tmp)
    {
        vt.push_back(tmp);
    }
    if(vt.size() > 2)
    {
        cout << "Ho: " << vt[0] << "\nLot: ";
        for(int i = 1; i <= vt.size() - 2; i++)
        {
            cout << vt[i] << " ";
        }
        cout << "\nTen: " << vt.back();
    }
    else
    {
        cout << "Ho: " << vt[0] << "\nTen: " << vt[1]; 
    }
    return 0;
}
