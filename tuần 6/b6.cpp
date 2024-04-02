#include <iostream>
using namespace std;
int ucln (int m, int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (m % i == 0 and n % i == 0 and i > max) {max = i;}
    }
    return max;
}
int main ()
{
    int m, n;
    cin >> m >> n;
    cout << ucln (m, n);
}
