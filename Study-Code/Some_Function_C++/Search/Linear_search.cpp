#include <iostream>
using namespace std;

int linear_search(int arr[],int n,int x) 
{
  for(int i = 0; i < n; i++)
    {
      if(arr[i] == target)
        return i;
    }
  return -1;
}

int main()
{
  int n, target; 
  cin >> n >> target;
  int arr[n];

  for(int i = 0; i < n; i++) 
  {
    cin >> arr[i];
  }

  int res = linear_search(arr,n,target);
  cout << res;
  
  return 0;
}
