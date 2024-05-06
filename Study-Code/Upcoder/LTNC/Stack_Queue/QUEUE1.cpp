#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> qe;
    char x;
    
    while(cin >> x)
    {
        if(x == '*')
        {
            if(qe.empty())
                continue;
            
            cout << qe.front();
            qe.pop();
        }
        else
        {
            qe.push(x);
        }
    }
    return 0;
}
