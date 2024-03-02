#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    string x = "*";
    string o = " ";
    int dem = n;
    int dem_trong = n - 1;
    int dem_sao = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int y = 0; y < dem; ++y)
        {
            if (y < dem_trong) {cout << o;}
            else cout << x;
        }
        ++dem;
        --dem_trong;
        cout << endl;
        }
}
