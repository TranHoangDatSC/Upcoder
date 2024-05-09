#include <iostream>
#include <string>
#include <vector>
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

int main()
{
    int n;
    cin >> n;
    string str;
    
    vector<int> vt;
    int index = 1;
    
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        if(LoginUp(str))
            vt.push_back(index);
        
        index++;
    }
    
    cout << vt.size() << "\n";
    for(int i = 0; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
    return 0;
}
