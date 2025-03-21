#include <iostream>
using namespace std;

int n, ans;
const int MaxN = 20 + 5;
int arr[MaxN][MaxN];

bool Check(int row, int col) {
    for(int i = 1; i <= row; i++) 
        if(arr[i][col])
            return false;
    
    for(int i = row, j = col; i >= 1 && j >= 1; i--, j--) 
        if(arr[i][j])
            return false;

    for(int i = row, j = col; i >= 1 && j <= n; i--, j++) 
        if(arr[i][j])
            return false;
    
    return true;
}

void Try(int row) {
    if(row > n) {
        ans++; 
        return;
    }
    for(int col = 1; col <= n; col++) {
        if(Check(row,col)) {
            arr[row][col] = 1;
            Try(row + 1);
            arr[row][col] = 0;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    cout << ans;
    return 0;
}
