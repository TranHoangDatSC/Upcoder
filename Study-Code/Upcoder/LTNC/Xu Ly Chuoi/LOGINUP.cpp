#include <iostream>
#include <string>
using namespace std;

bool LoginUp(string str)
{
    char tmp[] = {'u','p','c','o','d','e','r'};
    int index = 0;
    for(char x : str)
    {
        if(x == tmp[index])
            index++;
    }
    return index == 7;
}

using namespace std;

int main() {
    string str;
    cin >> str;
    cout << (LoginUp(str) ? "YES" : "NO");
    return 0;
}
