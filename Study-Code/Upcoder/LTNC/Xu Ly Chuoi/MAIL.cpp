#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        bool check = true;
        stringstream ss(str);
        
        char token;
        vector<char> vt;
        while(ss >> token)
        {
            vt.push_back(token);
        }
        
        for(int i = 0; i < vt.size(); ++i)
        {
            if(vt[i] == '@')
            {
                check = true;
                break;
            }
            else 
            {
                check = false;
            }
        }
        if(check == true)
            cout << str << endl;
        else cout << "";
    }
    return 0;
}
