#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<int> pos;

    if(str.size() < 3)
    {
        int a = str[0] - 48;
        int n;

        while (cin>>n) 
        {
            pos.push_back(n);
        }

        if(str[0] != '-') 
            pos.erase(pos.begin() + a);
        else 
            pos.clear();
    }

    else 
    {
        int a = str[0] - 48;
        int b = str[2] - 48;

        int n;

        while (cin>>n) 
        {
            pos.push_back(n);
        }

        pos.erase(pos.begin() + a, pos.begin() + b);
    }

    if(!pos.empty())
    {
        for (int i=0;i < pos.size(); i++)
            cout << pos[i] << " ";
    }
    else cout << "empty";

    return 0;
}
