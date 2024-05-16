#include <iostream>
using namespace std;
//1. Tạo hàm đệ quy
int deQuy(int n, int x)
{
    if(n == 0) return 1;
    else if(n == 1) return x;
    else return x * deQuy(n - 1,x);
}

int main()
{
    int n,x;
    cin >> n >> x;
    cout << deQuy(n,x);
    return 0;
}
