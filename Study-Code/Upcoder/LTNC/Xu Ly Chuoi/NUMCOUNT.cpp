#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int count(string str)
{
    stringstream ss(str);
    int cnt = 0;
    string num;
    while(ss >> num)
    {
        cnt++;
    }
    return cnt;
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        cout << count(str) << "\n";
    }
    return 0;
}
