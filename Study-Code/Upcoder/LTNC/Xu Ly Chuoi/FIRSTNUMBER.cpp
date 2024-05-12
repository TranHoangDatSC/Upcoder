#include <string>
#include <iostream>
using namespace std;

string chuyenDoi(int n)
{
    string str = "";
    int number = 1;
    
    while(str.size() < n)
    {
        str += to_string(number);
        number++;
    }
    return str;
}

int timViTri(int n, string str)
{
    int pos = str.find(to_string(n));
    
    if(pos != string::npos)
    
        return pos + 1;
        
    return -1;
}

int main()
{
    int n;
    cin >> n;
    
    string str = chuyenDoi(1000000);
    
    int pos = timViTri(n,str);
    cout << pos;
    return 0;
}
