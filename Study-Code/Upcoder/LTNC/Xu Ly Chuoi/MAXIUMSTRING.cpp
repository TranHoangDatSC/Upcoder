#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int m, s; 
    cin >> m >> s;

    if ((m > 1 && s == 0) || s > m * 9)
    {
        cout << -1;
        return 0;
    }
    else if (m == 1 && s == 0)
    {
        cout << 0 << endl << 0;
        return 0;
    }
    
    int s2 = s;
    int min[m], max[m];
    
    memset(min,0,sizeof(min));
    memset(max,0,sizeof(max));
    
    for(int i = m - 1; i >= 0; i--)
    {
        if(s >= 9)
        {
            min[i] += 9;
            s -= 9;
        }
        else if(s > 0)
        {
            min[i] += s;
            s = 0;
        }
    }
    
    if(min[0] == 0)
    {
        int i = 1;
        while(min[i] == 0)
            i++;
            
        min[0] += 1; min[i] -= 1;
    }
    for(int i = 0; i < m; i++)
    {
        if(s2 >= 9)
        {
            max[i] += 9;
            s2 -= 9;
        }
        else if(s2 > 0)
        {
            max[i] += s2;
            s2 = 0;
        }
    }
    
    for(int z : min)
        cout << z;
    
    cout << endl;
    
    for(int z : max)
        cout << z;
    
    return 0;
}


/*
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int m, s; cin >> m >> s;
    if ((m>1&&s==0)||s>m*9){
        cout << -1;
        return 0;
    }
    else if (m==1&&s==0){
        cout << 0 << endl << 0;
        return 0;
    }
    int s2=s;
    int minans[m], maxans[m];
    memset(minans,0,sizeof(minans));
    memset(maxans,0,sizeof(maxans));
    for (int i=m-1 ; i>=0 ; i--){
        if (s>=9){
            minans[i]+=9;
            s-=9;
        }
        else if (s>0){
            minans[i]+=s;
            s=0;
        }
    }
    if (minans[0]==0){
        int i=1;
        while(minans[i]==0){
            i++;
        }
        minans[0]+=1; minans[i]-=1;
    }
    for (int i=0 ; i<m ; i++){
        if (s2>=9){
            maxans[i]+=9;
            s2-=9;
        }
        else if (s2>0){
            maxans[i]+=s2;
            s2=0;
        }
    }
    for (int x:minans){
        cout << x;
    }
    cout << endl;
    for (int x:maxans){
        cout << x;
    }
    return 0;
}
*/
