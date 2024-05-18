#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer
{
    string id;
    string name;
    int money;
    
    friend istream& operator >> (istream& is, Customer& cs)
    {
        string str, token;
        vector<string> vt;
        getline(is,str);
        
        stringstream ss(str);
        
        while(ss >> token)
        {
            if(token != "-")
                vt.push_back(token);
        }
        
        cs.id = vt.front();
        cs.money = stoi(vt.back());
        
        for(string s : vt)
        {
            if(isalpha(s[0]))
                cs.name += s + " ";
        }
        
        return is;
    }
    friend ostream& operator << (ostream& os, Customer cs)
    {
        os << cs.id << " - " << cs.name << " -" << cs.money;
        return os;
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    vector<Customer> v(n);
    
    for(Customer &x : v)
        cin >> x;
        
    cout << count_if(v.begin(), v.end(), [] (Customer x) 
    {return x.money >= 0;});
    cout << "\n";
    
    sort(v.begin(),v.end(), [] (Customer a, Customer b) 
    {return a.money < b.money;});
    
    cout << v[n-1];
    
    return 0;
}
