#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool snt(int n)
{
    if(n < 2)
        return false;
    else 
    {
        for(int i = 2; i <= sqrt((float)n); i++)
        {
            if(n % i == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    string n;
    cin >> n;
    
    int sum = 0;
    bool isPrime = true;
    
    for(char c : n)
    {
        int digit = c - '0';
        sum += digit;
        
        if(!snt(digit))
        {
            isPrime = false;
        }
    }
    
    cout << ((snt(sum) && isPrime) ? "YES" : "YESNOT");
    return 0;
}
