#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifile("input.txt");
    int a, b;
    ifile >> a >> b;
    ifile.close();
    cout << a + b;
    return 0;
}
