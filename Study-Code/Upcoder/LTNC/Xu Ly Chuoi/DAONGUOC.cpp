#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main () {
    string str;
    cin >> str;
    stringstream ss(str);
    ss << str << " ";
    
    char word;
    vector<char> vt;
    while(ss >> word)
    {
        vt.push_back(word);
    }
    for(int i = vt.size() - 1; i >= 0; i--)
    {
        cout << vt[i];
    }
    return 0;
}
