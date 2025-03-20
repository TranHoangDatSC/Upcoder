// Tìm UCLN theo 2 cách đệ quy

#include <iostream>
#include <cmath>
using namespace std;

int GCD_Substraction(int a, int b) {
    if(a == b) return a;
    if(a > b) return GCD_Substraction(a - b, b);
    return GCD_Substraction(a, b - a);
}
int GCD_Euclid(int a, int b) {
    if(b == 0) return a;
    return GCD_Euclid(b, a % b);
}


int main() {
    int a,b;
    cin >> a >> b;
    cout << GCD_Substraction(a,b);

    return 0;
}
