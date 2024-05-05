#include <iostream>
#include <string>
#include <vector>
#include <set>
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
    string str;
    cin >> str;
    
    set<char> s;
    for(char x : str)
    {
        s.insert(x);
    }
    
    if(s.size() == 26) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
