#include <iostream>
using namespace std;
void tamgiac (int n)
{
    char o = ' ';
    char x = '*';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n + i; ++j)
        {
            if (j < n - i) {cout << o;}
            else cout << x;
        }
        cout << endl;
    }
}
int main ()
{
    int n;
    cin >> n;
    tamgiac(n);
}
