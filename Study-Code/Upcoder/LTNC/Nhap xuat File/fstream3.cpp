#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    ofstream ofile("out.txt");
    ofile << a + b;
    ofile.close();
    return 0;
}
