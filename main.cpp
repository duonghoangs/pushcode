#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    string x = "*";
    string o = " ";
    string a[n][n];
    int trong = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int y = 0; y < n; ++y)
        {
            if (y < trong)a[i][y] = o;
            else a[i][y] = x;
        }
        ++trong;
    }
    
    
    for (int i = 0; i < n; ++i)
    {
        for (int y = 0; y < n; ++y)
        {
            cout << a[i][y];
        }
        cout << endl;
    }
    
}
    
    
    
