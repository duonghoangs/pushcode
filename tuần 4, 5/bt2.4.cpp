#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            if (j == 0 or j == i ) {a[i][j] = 1;}
            else {a[i][j] = a[i - 1][j] + a[i - 1][j - 1];}
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}



    
