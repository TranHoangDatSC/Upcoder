#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifile("input.txt");
    int a, b;
    ifile >> a >> b;
    ifile.close();
    
    ofstream ofile("output.txt");
    ofile << a + b;
    ofile.close();
    return 0;
}
