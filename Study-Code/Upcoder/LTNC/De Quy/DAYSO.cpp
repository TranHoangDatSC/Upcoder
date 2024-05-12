#include <iostream>
using namespace std;

int maxNumber(int n) {
    if(n < 2)
        return n;
    if(n % 2 == 0)
        return maxNumber(n/2);
    else 
        return maxNumber(n/2) + maxNumber(n/2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int max = -1;
    for(int i = 0; i <= n; i++)
    {
        if(maxNumber(i) > max)
            max = maxNumber(i);
    }
    cout << max;
    
    return 0;
}
