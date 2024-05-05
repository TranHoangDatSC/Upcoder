#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

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

/*
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int a[25] = {0};
    for(char x : str)
    {
        a[x - 'a'] = 1;
    }
    
    for(int i = 0; i < 26; i++)
    {
        if(!a[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
*/
