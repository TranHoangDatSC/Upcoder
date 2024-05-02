#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    vector<int> position;
    string arrNum;
    getline(cin,arrNum);
    
    for(int i=0;i<arrNum.size();i += 2)
    {
        position.push_back(arrNum[i] - 48);
    }
    
    string str;
    getline(cin,str);
    
    if(str.size() < 3)
    {
        if (str[0] == '-') 
            position.clear();
        else 
        {
            int a = str[0] - 48;
            position.erase(position.begin() + a);
        }
    }
    else 
    {
        int a = str[0] - 48;
        int b = str[2] - 48;
        position.erase(position.begin() + a, position.begin() + b);
    }
    
    if (position.empty()) 
        cout << "empty";
    else 
    {
        for(int i=0;i<position.size();i++)
        {
            cout << position[i] << " ";
        }
    }
    return 0;
}
