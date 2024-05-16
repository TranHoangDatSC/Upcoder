#include <iostream> 
#include <string>
#include <vector>
using namespace std;

string removeZero(string num)
{
    int i = 0;
    while(i < num.size() && num[i] == '0')
    {
        i++;
    }
    return (i == num.size()) ? "0" : num.substr(i); 
}

int main()
{
    string str;
    cin >> str;
    
    vector<string> vt;
    string token = "";
    
    for(char x : str)
    {
        if(isdigit(x))
            token += x;
        else
        {
            if(!token.empty())
            {
                vt.push_back(removeZero(token));
                token = "";
            }
        }
    }
    
    if(!token.empty())
    {
        vt.push_back(removeZero(token));
    }
    
    string max = "0";
    
    for(string num : vt)
    {
        if(num.size() > max.size() || (num.size() == max.size() && num > max))
        {
            max = num;
        }
    }
    
    cout << max;
    
    return 0;
}
