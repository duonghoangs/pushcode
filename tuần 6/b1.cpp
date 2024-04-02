#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random (int x)
{
    int a;
    time_t t;
    srand((unsigned) time(&t));
    a = rand() % x;
    return a;
}
int** taobang(int** a, int m, int n)
{
    a = new int* [m];
    for (int i = 0; i < m; ++i)
    {
        a[i] = new int [n];
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            a[i][j] = 0;
        }
    }
    return a;
}
int** taomin(int** a, int m, int n, int k)
{
    while (k != 0)
    {
        int x = random (m);
        int y = random (n);
        if (a[x][y] != 9) {a[x][y] = 9; --k;}
    }
    return a;
}
bool checkmin (int x)
{
    if (x == 9) {return false;}
    return true;
}
int** checkbang (int** a, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 9)
            {
                if (a[i + 1][j + 1] != 9 and i + 1 < m and j + 1 < n) {a[i + 1][j + 1] += 1;}
                if (a[i + 1][j] != 9 and i + 1 < m) {a[i + 1][j] += 1;}
                if (a[i + 1][j - 1] != 9 and i + 1 < m and j - 1 >= 0) {a[i + 1][j - 1] += 1;}
                if (a[i - 1][j - 1] != 9 and i - 1 >= 0 and j - 1 >= 0) {a[i - 1][j - 1] += 1;}
                if (a[i - 1][j] != 9 and i - 1 >= 0) {a[i - 1][j] += 1;}
                if (a[i - 1][j + 1] != 9 and i - 1 >= 0 and j + 1 < n) {a[i - 1][j + 1] += 1;}
                if (a[i][j - 1] != 9 and j - 1 >= 0) {a[i][j - 1] += 1;}
                if (a[i][j + 1] != 9 and j + 1 < n) {a[i][j + 1] += 1;}
            }
        }
    }
    return a;
}
void inbang (int** a, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main ()
{
    int m, n, k, x, y;
    cout << "nhap cac thong so: ";
    cin >> m >> n >> k;
    int** b = taobang(b, m, n);
    int** a = taobang(a, m, n);
    a = taomin(a, m, n, k);
    a = checkbang(a, m, n);
    for (int i = 0; i < m*n; ++i)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        if (checkmin(a[x][y]))
        {
            b[x][y] = a[x][y];
            inbang (b, m, n);
        }
        else 
        {
            cout << "YOU ARE DEAD!" << endl;
            inbang(a, m, n);
            return 0;
        }
    }
    cout << "đẳng cấp";
}
