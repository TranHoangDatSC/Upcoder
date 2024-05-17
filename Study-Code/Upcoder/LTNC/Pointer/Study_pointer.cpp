#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int **arr = new int*[5]; // so hang (5 hang)
    
    for(int i = 0; i < 5; i++)
    {
        arr[i] = new int[10]; // so cot (10 cot)
    }
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            arr[i][j] = i*10 + j;
        }
    }
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << arr[i][j] /*+1*/ << " ";
        }
        cout << endl;
    } // k can output
    return 0;
}

/* Luyen tap mang 1 chieu
#include <iostream>
#include <algorithm>
using namespace std;


// dieu kien sap xep giam dan
bool dieukiensort(int a, int b)
{
    return a > b;
}

int main()
{
    int *arr = new int[5];
    
    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    
    //reverse(arr + 0, arr + 5);
    
    //sort(arr, arr + 5); sort tang dan
    
    //sort(arr, arr + 5, dieukiensort); 
    sort(arr, arr + 5, [] (int a, int b) {return a > b;});
    // sap xep giam dan
    
    
    for(int i = 0; i < 5; i++)
    {
        //cout << arr[i] << " ";
        cout << *(arr + i) << " ";
    }
    
    delete[] arr;    
    return 0;
}
*/ 
