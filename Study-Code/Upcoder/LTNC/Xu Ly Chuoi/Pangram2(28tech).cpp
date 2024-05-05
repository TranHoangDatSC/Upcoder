#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    while(n--)
    {
        string str;
        getline(cin, str);
        
        stringstream ss(str);
        
        string tmp;
        int cnt = 0;
        while(ss >> tmp)
        {
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
