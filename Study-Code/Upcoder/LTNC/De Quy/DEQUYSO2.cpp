#include <iostream>
#include <vector>
using namespace std;

int countALL(int n, int k, int s, int index, int sum, vector<int>& subset)
{
    if(k == 0 && sum == s)
        return 1;
    if(index > n || k < 0 || sum > s)
        return 0;
    
    int notInclude = countALL(n, k, s, index + 1, sum, subset);
    subset.push_back(index);
    
    int Include = countALL(n, k - 1, s, index + 1, sum + index, subset);
    subset.pop_back();
    
    return notInclude + Include;
}

int sumSet(int n, int k, int s)
{
    vector<int> sets;
    return countALL(n,k,s,1,0,sets);
}

int main()
{
    int n,k,s;
    cin >> n >> k >> s;
    
    int res = sumSet(n,k,s);
    
    cout << res;
    return 0;
}
