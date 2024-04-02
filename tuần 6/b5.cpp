#include <iostream>
using namespace std;
bool nguyento (int n)
{
    int s = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0) { ++s;}
    }
    if (s == 2) return 1;
    return 0;
}


int main ()
{
    int n;
    cin >> n;
    cout << nguyento (n);
}
