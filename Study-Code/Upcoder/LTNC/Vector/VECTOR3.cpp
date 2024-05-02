#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool KtraSCP(int n) 
{
    int k = sqrt(n);
    return k * k == n;
}

bool Check(int n)
{
    if(KtraSCP(n)==true||n%2!=0)
        return true;
    return false;
}

int main() {
    vector<int> a;
    vector<int>::iterator it = a.begin();
    int input;
    while(cin >> input) 
    {
        a.push_back(input);
    }
    
    a.erase(remove_if(a.begin(),a.end(),Check),a.end());

    sort(a.begin(),a.end());
    for(it = a.begin();it!=a.end();it++)
    {
        cout << *it << " ";
    }
    
    return 0;
}
