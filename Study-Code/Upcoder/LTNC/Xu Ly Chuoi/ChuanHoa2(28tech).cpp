#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

void vietHoa(string &str)
{
    for(int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
}

void chuanHoa(string &str)
{
    str[0] = toupper(str[0]);
    for(int i = 1; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    map<string, int> mp;
    
    while(n--)
    {
        string str;
        getline(cin,str);
        for(int i = 0;i < str.size(); i++)
        {
            str[i] = tolower(str[i]);
        }
        vector<string> vt;
        stringstream ss(str);
        
        string tmp;
        string res = "";
        while(ss >> tmp)
        {
            vt.push_back(tmp);
        }
        
        chuanHoa(vt[vt.size() - 1]);
        cout << vt.back() << ", ";
        
        for(int i = 0; i < vt.size() - 1;i++)
        {
            chuanHoa(vt[i]);
            cout << vt[i];
            if(i != vt.size() - 1)
                cout << " ";
        }
        cout << '\n';
    }
    return 0;
}
