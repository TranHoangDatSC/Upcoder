#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string word;
    
    getline(cin,str);
    getline(cin,word);
    
    int pos = str.find(word);
    
    while(pos != string::npos)
    {
        str.erase(pos,word.size());
        pos = str.find(word,0);
    }
    
    pos = str.find("  ");
    if(pos != string::npos)
        str.erase(pos,1);
    
    cout << str;
    
    return 0;
}
