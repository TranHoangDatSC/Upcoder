// Tính tổng chữ số trong chuỗi. Ví dụ: 12345 = 15 | 1 23 4 56 = 21

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int Sum_Digits(string& str, int idx = 0) {
    if(idx == str.size()) return 0;
    
    char c = str[idx];
    int current = isdigit(c) ? c - '0' : 0;
    
    return current + Sum_Digits(str, idx + 1);
}

int main()
{
    string input;
    getline(cin, input);
    cout << Sum_Digits(input);
    
    return 0;
}
