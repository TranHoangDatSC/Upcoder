#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int solveWord(string str)
{
    vector<string> vt;
    

    str[0] = tolower(str[0]);
    int i = 0;  // Chỉ số để duyệt qua chuỗi
    int check = 0;  // Chỉ số bắt đầu của một chuỗi con có các ký tự liên tiếp giống nhau
    
    // Vòng lặp duyệt qua chuỗi
    while(i < str.size())
    {
        // Kiểm tra nếu ký tự hiện tại giống với ký tự tiếp theo
        if(str[i] == str[i+1])
        {
            // Nếu chúng giống nhau, trích xuất chuỗi con và thêm vào vector
            vt.push_back(str.substr(check, i - check + 1)); // Thêm chuỗi con vào vector
            
            // Bỏ qua tất cả các ký tự liên tiếp giống nhau
            while(str[i] == str[i+1])
            {
                ++i; // Di chuyển đến ký tự tiếp theo
                if(i+1 >= str.size()) // Kiểm tra nếu đã đến cuối chuỗi
                    return vt.size(); // Trả về kích thước của vector nếu đã đến cuối chuỗi
            }
            check = i + 1; // Cập nhật chỉ số bắt đầu của chuỗi con tiếp theo
        }
        ++i; // Di chuyển đến ký tự tiếp theo
    }
    
    // Loại bỏ các chuỗi con trùng lặp trong vector
    sort(vt.begin(), vt.end());
    vt.erase(unique(vt.begin(), vt.end()), vt.end());
    
    // Trả về kích thước của vector cộng thêm một
    return vt.size() + 1;
}

int main()
{
    string str;
    cin >> str; // Đọc chuỗi đầu vào từ người dùng
    
    cout << solveWord(str); // In ra kết quả của hàm solveWord
    
    return 0;
}
/*
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Function to solve the problem based on the given string
int solveWord(string str)
{
    vector<string> vt; // Vector to store substrings with consecutive characters
    
    // Convert the first character of the string to lowercase
    str[0] = tolower(str[0]);
    int i = 0;  // Index to traverse the string
    int check = 0;  // Starting index of a substring with consecutive characters
    
    // Loop through the string
    while(i < str.size())
    {
        // Check if the current character is the same as the next character
        if(str[i] == str[i+1])
        {
            // If they are the same, extract the substring and add it to the vector
            vt.push_back(str.substr(check, i - check + 1)); // Add substring to vector
            
            // Skip all consecutive characters
            while(str[i] == str[i+1])
            {
                ++i; // Move to the next character
                if(i+1 >= str.size()) // Check if the end of the string is reached
                    return vt.size(); // Return the size of the vector if end of string is reached
            }
            check = i + 1; // Update the starting index of the next substring
        }
        ++i; // Move to the next character
    }
    
    // Remove duplicate substrings from the vector
    sort(vt.begin(), vt.end());
    vt.erase(unique(vt.begin(), vt.end()), vt.end());
    
    // Return the size of the vector plus one
    return vt.size() + 1;
}

int main()
{
    string str;
    cin >> str; // Read input string from the user
    
    cout << solveWord(str); // Output the result of solveWord function
    
    return 0;
}

*/
