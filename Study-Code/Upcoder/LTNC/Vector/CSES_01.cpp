#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, a, i = 0; 
    cin >> n >> k;
    vector<int> arr;
    
    // Đọc dữ liệu vào vector arr
    while (i++ < n) {
        cin >> a; 
        arr.push_back(a);
    }
    
    // Sắp xếp vector arr để dễ dàng tìm kiếm
    sort(arr.begin(), arr.end());
    
    // Duyệt qua từng phần tử trong arr để tìm cặp phần tử có tổng bằng k
    for (int j = 0; j < n; ++j) {
        int tmp = arr[j]; 
        
        // Tìm kiếm phần tử k-tmp trong arr
        auto it = lower_bound(arr.begin(), arr.end(), k - tmp);
        
        // Kiểm tra xem phần tử này có tồn tại và không trùng với phần tử hiện tại không
        if (it != arr.end() && *it == k - tmp && it - arr.begin() != j) {
            cout << tmp << " " << *it;
            return 0;
        }
    }
    cout << -1;
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a, i = 0; 
    cin >> n >> k;
    multiset<int> arr;
    while (i++ < n) 
    {
        cin >> a; 
        arr.insert(a);
    }
    for (auto x : arr) 
    {
        int tmp = x; 
        arr.erase(arr.find(x));
        if (arr.count(k-tmp) != 0) 
        {
            cout << tmp << " " << k-tmp;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
*/
