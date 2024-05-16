#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

double sum(int n)
{
    if(n == 1) return 0.5;
    return 1.0 / (1 + sum(n - 1));
}

bool check(string str)
{
    for(char c : str)
        if(!isdigit(c))
            return false;
    
    return true;
}

int main()
{
    string n;
    cin >> n;
    
    if(!check(n) || n == "0")
    {
        cout << -1;
        return 0;
    }
    
    int k = stoi(n);
    cout << setprecision(4) << fixed << sum(k);
    
    return 0;
}
