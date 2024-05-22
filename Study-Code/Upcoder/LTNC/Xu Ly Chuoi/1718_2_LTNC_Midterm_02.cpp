#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Anagram(string s1, string s2)
{
    if(s1.size() != s2.size())
        return false;

    string cs1 = s1;
    string cs2 = s2;
    
    sort(cs1.begin(), cs1.end());
    sort(cs2.begin(), cs2.end());
    
    return cs1 == cs2;

}


int main()
{
    string s1,s2;
    
    getline(cin,s1);
    getline(cin,s2);
    
    if(Anagram(s1,s2))
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}
