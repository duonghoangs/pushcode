
#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i)
    {
        int x = 1;
        for (int y = 1; y <= n; ++y)
        {
            a[i][y] = x + i;
            if (x + i == n) {x = 0 - i;}
            ++x;
            cout << a[i][y] << " ";
        }
        cout << endl;
    }
    
}
