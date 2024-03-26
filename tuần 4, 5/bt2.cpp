

#include <iostream>
using namespace std;
int main ()
{
    string n;
    cin >> n;
    int s = n.size();
    for (int i = 0; i < s / 2; ++i)
    {
        cout << s/ 2;
        if (n[i] != n[s - i - 1]) {cout << "NO"; return 0;}
    }
    cout << "YES";
    
    return 0;
}
