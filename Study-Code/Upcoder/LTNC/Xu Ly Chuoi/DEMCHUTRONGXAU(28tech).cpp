#include <iostream>
#include <string>
#include <vector>
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
        getline(cin,str);
        stringstream ss(str);
        
        string token;
        int cnt = 0;
        while(ss >> token)
        {
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
