#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool stringpbrk(string str)
{
    string cdt = "bdfhkt";
    for(char x : str)
    {
        if(cdt.find(x) != string::npos)
            return false;
    }
    return true;
}

int main()
{
    string str, res;
    
    while(getline(cin,str))
    {
        stringstream ss(str);
        string word;
        
        while(ss >> word)
        {
            if(stringpbrk(word))
            {
                if(word.size() > res.size())
                    res = word;
            }
        }
    }
    cout << res;
    
    return 0;
}
