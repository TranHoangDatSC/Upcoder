#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    string str;

    while(getline(cin,str))
    {
        vector<double> vt;
        stringstream ss(str);
        double tmp;

        while(ss >> tmp)
        {
            vt.push_back(tmp);
        }
        double sum = 0;
        for(int i = 0; i < vt.size(); i++)
        {
            sum += vt[i];
        }
        cout << roundf(sum*1000) / 1000 << "\n";
    }
    return 0;
}
