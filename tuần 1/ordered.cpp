#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    bool b;
    if ((x > y and y > z) or (x < y and y < z)) {b = true;}
    else b = false;
    cout << b;
}
