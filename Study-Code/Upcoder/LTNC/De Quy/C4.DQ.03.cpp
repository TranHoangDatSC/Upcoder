#include <iostream>
using namespace std;

int S(int a,int b,int c,int n) {
    if(n == 0) 
        return 3;
    else if(n == 1) 
        return -a;
    else if(n == 2) 
        return a*a - 2*b;
    else if (n >= 3) 
        return -a*S(a,b,c,n-1) - b*S(a,b,c,n-2) - c*S(a,b,c,n-3);
}

int main() {
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    
    cout << "S(n)=" << S(a,b,c,n);
    return 0;
}
