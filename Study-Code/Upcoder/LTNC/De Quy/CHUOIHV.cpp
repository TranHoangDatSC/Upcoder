#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string a, string b)
{
    if(a.size() != b.size())
        return false;
    
    int cntB[26] = {0};
    for(char x : b)
    {
        cntB[x - 'a']++;
    }
    for(char x : a)
    {
        cntB[x - 'a']--;
    }
    
    // Nếu tất cả các giá trị trong mảng đếm đều bằng 0, tức là A là hoán vị của B
    return all_of(cntB, cntB + 26, [](int x) {return x == 0;});
}

int main()
{
    string a,b;
    getline(cin, a);
    cin.clear();
    getline(cin, b);
    
    cout << (check(a,b) ? "True" : "False");
    
    return 0;
}

/* Example for all_of

#include<iostream>
#include<algorithm> // for all_of()
using namespace std;
int main()
{
    // Initializing array
    int ar[6] = {1, 2, 3, 4, 5, -6};
 
    // Checking if all elements are positive
    all_of(ar, ar+6, [](int x) { return x>0; })?
        cout << "All are positive elements" :
        cout << "All are not positive elements";
 
    return 0;
 
}


*/
