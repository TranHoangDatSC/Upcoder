#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], target;
    cin >> target;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
        
    for (int i = 0; i < n; i++) {
        if(arr[i] == target)    
            cout << i << " ";
    }
    
    return 0;
}
// Cải tiến giải thuật tìm kiếm tuyến tính để có thể liệt kê tất cả các v trí xuất hiện của target.
