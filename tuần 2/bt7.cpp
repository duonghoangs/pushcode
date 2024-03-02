#include <iostream>
using namespace std;
int main ()
{
    int n;
    int x = -999;
    while (n > 0)
    {
        cin >> n;
        if (n != x) {cout << n << " ";}
        x = n;
    }
}
