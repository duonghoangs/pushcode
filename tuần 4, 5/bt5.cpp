#include <iostream>
using namespace std;

int main ()
{
    int x, y;
    cin >> x >> y;
    int a[x][y];
    int hethang = x - 1;
    int hetcot = y - 1;
    int dauhang = 0;
    int daucot = 0;
    int n = 1;
    while (dauhang <= hethang and daucot <= hetcot)
    {
        for (int i = daucot; i <= hetcot; ++i)
        {
            a[dauhang][i] = n; ++n;
        }
        dauhang++;
        for (int i = dauhang; i <= hethang; ++i)
        {
            a[i][hetcot] = n; ++n;
        }
        hetcot--;
        for (int i = hetcot; i >= daucot; --i)
        {
            a[hethang][i] = n; ++n;
        }
        hethang--;
        for (int i = hethang; i >= dauhang; --i)
        {
            a[i][daucot] = n; ++n;
        }
        daucot++;
    }
    
    
    
    
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
