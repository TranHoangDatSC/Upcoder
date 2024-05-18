#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void chuanHoa(string& str)
{
    str[0] = toupper(str[0]);
    for(int i = 1; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    string str;
    getline(cin,str);
    
    stringstream ss(str);
    string token;
    vector<string> vt;
    while(ss >> token)
    {
        vt.push_back(token);
    }
    
    for(int i = 0; i < vt.size(); i++)
    {
        chuanHoa(vt[i]);
        cout << vt[i];
        if(i != vt.size() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string name;
    
    while(cin >> name)
    {
        name[0] = toupper(name[0]);
        for(int i = 1; i < name.size(); i++)
        {
            name[i] = tolower(name[i]);
        }
        cout << name << " ";
    }
    return 0;
}
*/
