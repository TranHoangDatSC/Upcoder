#include <iostream>
#include <string>
using namespace std;

string transformNum(string &str,char from,char to) {
    string result = str;
    for(char &c : result) {
        if(c == from) {
            c = to;
        }
    }
    return result;
}

long long Sum(long long a, long long b, char from, char to) {
    string strA = to_string(a);
    string strB = to_string(b);
    
    long long resultA = stoll(transformNum(strA,from,to));
    long long resultB = stoll(transformNum(strB,from,to));
    return resultA + resultB;
}

int main() {
    long long a,b;
    cin >> a >> b;
    long long result45 = Sum(a,b,'4','5');
    long long result54 = Sum(a,b,'5','4');
    
    long long max = result45;
    long long min = result54;
    
    if(max < result54 || min > result45) {
        max = result54;
        min = result45;
    }
    else {
        max = result45;
        min = result54;
    }
    
    cout << max << " " << min;
    return 0;
}
