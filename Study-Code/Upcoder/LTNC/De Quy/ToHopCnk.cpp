#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int tohopChapCnk(int n, int k)
{
    if(k == 0 || n == k)
        return 1;
    else return tohopChapCnk(n - 1, k - 1) + tohopChapCnk(n - 1, k);
}

int main()
{
    int n,k;
    cin >> n >> k;
    cout << tohopChapCnk(n,k);
    return 0;
}
