#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > edge; // Luu danh sach canh
int adj[1001][1001];
vector<int> vt[1001];

int main()
{
    cin >> n;
    cin.ignore();
    
    for(int i = 1; i <= n; i++)
    {
        string s, num;
        getline(cin,s);
        
        stringstream ss(s);
        while(ss >> num)
        {
            adj[i][stoi(num)] = 1;
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

