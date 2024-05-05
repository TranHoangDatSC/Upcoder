#include <iostream>
#include <vector>
using namespace std;

vector<int> SolveFactorial(int n)
{
    vector<int> ftr(n + 1, 0);
    
    for(int i = 2; i <= n; i++)
    {
        int currentN = i;
        for(int j = 2; j <= currentN; j++)
        {
            while(currentN % j == 0)
            {
                ftr[j]++;
                currentN /= j;
            }
        }
    }
    return ftr;
}

int Count(int n)
{
    vector<int> ftr = SolveFactorial(n);
    int cnt = 1;
    
    for(int i = 2; i <= n; i++)
    {
        if(ftr[i] > 0)
            cnt *= (ftr[i] + 1);
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << Count(n);
    return 0;
}

/*
Giả sử chúng ta muốn tính số lượng các ước của giai thừa của số nguyên dương nào đó, trong trường hợp này là n = 4.

Bước 1: Nhập số n từ người dùng. Trong ví dụ này, chúng ta nhập n = 4.

Bước 2: Chương trình tính số lượng các ước của 4! bằng cách gọi hàm Count(4).

Bước 3: Hàm Count(4) gọi hàm SolveFactorial(4) để tính số lượng các ước của 4!.

Bước 4: Hàm SolveFactorial(4) tính toán số lượng các ước của 4! bằng cách phân tích thừa số nguyên tố của từng số từ 2 đến 4.

Kết quả của phân tích thừa số nguyên tố cho 4! như sau:

2^3 * 3^1 * 4^0
Do đó, chúng ta có:

3 ước của 2: 2^0, 2^1, 2^2, 2^3
1 ước của 3: 3^0, 3^1
0 ước của 4 (vì 4 không phải là số nguyên tố)
Vì vậy, số lượng các ước của 4! là (3+1) * (1+1) * (0+1) = 4 * 2 * 1 = 8.

Bước 5: Hàm Count(4) sẽ trả về kết quả là 8.
*/
