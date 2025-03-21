#include <iostream>
using namespace std;

int n, count = 0;
int row[100], col[100];
int maincross[100], recross[100];

void PrintResult()
{
	cout << count;
}

void Try(int i)
{
	if (i == n)
	{
		count++;
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			if (col[j] == 0 && maincross[i - j + n] == 0 && recross[i + j] == 0)
			{
				row[i] = j; col[j] = 1;
				maincross[i - j + n] = 1;
				recross[i + j] = 1;
				Try(i + 1);
				maincross[i - j + n] = 0;
				recross[i + j] = 0;
				row[i] = 0; col[j] = 0;
			}
		}
	}
}


int main()
{
	cin >> n;
	Try(0);
	PrintResult();
    return 0;
}
