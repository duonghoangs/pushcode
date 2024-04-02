#include <iostream>
#include <math.h>
using namespace std;
int lamtronceilfloor (double s)
{
    if (ceil (s) - s <= 0.5) {return ceil(s);}
    return floor (s);
}
int lamtron (double s)
{
    int i = s;
    double x = s - i;
    if (x >= 0.5) {return i + 1;}
    return i;
}
int main ()
{
    double s;
    cin >> s;
    cout << lamtronceilfloor(s) << endl;
    cout << lamtron(s);
}
