#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    int n;
    int max = -1;
    
    stringstream ss, sss;
    
    while(cin >> str)
    {
        reverse(str.begin(), str.end());
        ss << str << " ";
        ss >> n;
        
        if(n > max)
            max = n;
    }
    
    sss << max;
    sss >> str;
    
    reverse(str.begin(), str.end());
    
    cout << str;
    return 0;
}
