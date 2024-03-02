#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    string x = "*";
    string o = " ";

    int dem = n;
    int dem_trong = 0;
    int so_sao = 1 + 2 * (n - 1);
    for (int i = 0; i < n; ++i)
    {
        for (int y = 0; y < so_sao; ++y)
        {
            if (y < dem_trong) {cout << o;}
            else cout << x;
        }
        --so_sao;
        ++dem_trong;
        cout << endl;
    }
}


