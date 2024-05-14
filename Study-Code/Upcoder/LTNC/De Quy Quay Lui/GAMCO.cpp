#include <iostream>
using namespace std;

char arr[100][100]; // mang ky tu

bool danhDau[100][100]; // false = chua di qua, true = da di qa

int xC, yC; // toa do con Bo
int xB, yB; // toa do chuong Bo

int n,m; // n dong, m cot

// 4 huong di chuyen
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int num_grid_come = 0; // so o da di qua
int min_way;    // luu lai do dai duong di ngan nhat

// xet vi tri tai grid x,y
void Try(int x, int y)
{
    if(x == xB && y == yB) // dieu kien dung
    {
        if(num_grid_come < min_way)
            min_way = num_grid_come;
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            int xMoi = x + dx[i];
            int yMoi = y + dy[i];
            
            if(0 <= xMoi && xMoi < n && 0 <= yMoi && yMoi < m // nam trong ban do
            && danhDau[xMoi][yMoi] == false && arr[xMoi][yMoi] != '*')
            {
                danhDau[xMoi][yMoi] = true;
                num_grid_come++;
                
                Try(xMoi,yMoi);
                
                // "quay lui"
                
                num_grid_come--;
                danhDau[xMoi][yMoi] = false;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
            
            if(arr[i][j] == 'C') // toa do xuat phat cua con bo
            {   // luu lai 
                xC = i;
                yC = j;
            }
            if(arr[i][j] == 'B') // toa do chuong bo
            {   // luu lai
                xB = i;
                yB = j;
            }
        }
    }
    /* kiem tra du lieu dau vao
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << danhDau[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    // di qua tu o xuat phat
    num_grid_come = 1;
    danhDau[xC][yC] = true; 
    
    min_way = n*m; // lon nhat la gia tri ban dau
    
    Try(xC,yC); // vi tri xuat phat
    
    cout << min_way - 1; // de bai khong tinh o ket thuc
    
    return 0;
}
