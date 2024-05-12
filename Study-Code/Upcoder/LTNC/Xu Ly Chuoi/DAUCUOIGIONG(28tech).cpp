#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    while(n--)
    {
        string str;
        getline(cin,str);
        
        map<char, int> mp;
        for(char x : str)
        {
            mp[x]++;
        }
        long long ams = str.size(); // cac xau con co mot ky tu8
        for(auto it : mp)
        {
            ams += it.second * (it.second - 1) / 2;
        }
        cout << ams;
    }
    return 0;
}

// Input:
// 1 abcbabc
// Output:
// 12 
// Vi chuoi co 7 xau con,  b-b-b thi co them 3 xau, hai cap a-a c-c la 2, 7+3+2 == 12

/*
Other way:

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    while(n--)
    {
        string str;
        getline(cin,str);
        
      //map<char, int> mp;
        int arr[256] = {0}; // ASCII
        for(char x : str)
        {
            arr[x]++;
        }
        long long ams = str.size(); // cac xau con co mot ky tu8
        for(int i = 0; i < 256; i++)
        {
            if(arr[i] != 0)
                ams += arr[i] * (arr[i] - 1) / 2;
        }
        cout << ams << "\n";
    }
    return 0;
}
*/
