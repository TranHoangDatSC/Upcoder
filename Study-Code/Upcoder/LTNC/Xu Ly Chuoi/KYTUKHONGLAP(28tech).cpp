#include <iostream>
#include <string>
#include <map>
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
        
        map<char, int> mp;
        for(char x : str)
        {
            mp[x]++;
        }
        for(char x : str)
        {
            if(mp[x] == 1)
                cout << x;
        }
        cout << "\n";
    }
    return 0;
}

/*
Input:
2 ABCEABC ADEDEF
Output:   
E 
AF
*/
