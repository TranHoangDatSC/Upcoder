#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

bool palindrome(string str)
{
    string s = str;
    
    transform(s.begin(), s.end(),s.begin(), ::tolower);
    s.erase(remove_if(s.begin(),s.end(), ::isspace), s.end());
    
    string reversed = s;
    
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

int main()
{
    ifstream ifile("input.txt");
    ofstream ofile("output.txt");
    
    string str;
    while(getline(ifile,str))
    {
        ofile << palindrome(str) << "\n";
    }
    
    ifile.close();
    ofile.close();
    return 0;
}
