#include <iostream>
using namespace std;

void swap(char &a,char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

bool check(char &a, char &b, char type) {
    if(type == 'A') return a > b;
    if(type == 'D') return a < b;
}

void sort(char arr[],char type,int n) {
    for(int i = 1; i < n; i++) {
        int j = i;
        
        while(j > 0 && check(arr[j-1],arr[j],type)) {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main() {
    char type;
    cin >> type;
    int n;
    cin >> n;
    
    char arr[n];
    for(char &x : arr)
        cin >> x;
        
    sort(arr,type,n);
    
    for(char &x : arr)
        cout << x << " ";
    
    return 0;
}
