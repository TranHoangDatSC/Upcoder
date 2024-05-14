#include <iostream>
using namespace std;

long coSo2_10(string nhiPhan, int chiSo = 0)
{
    if(chiSo == nhiPhan.size())
        return 0;
        
    return (nhiPhan[chiSo] - '0') * (1 << (nhiPhan.size() - 1 - chiSo)) 
    + coSo2_10(nhiPhan, chiSo + 1);
}

int main()
{
    string nhiPhan;
    cin >> nhiPhan;
    cout << coSo2_10(nhiPhan);
    return 0;
}
