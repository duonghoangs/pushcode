#include <iostream>
using namespace std;

// bài 1
struct point
{
    double x, y;
};


void print (point p)
{
    cout << p.x << " " << p.y;
}
void cinpoint (point &p)
{
    cin >> p.x >> p.y;
}




// bài 3
point midpoint (point a, point b)
{
    point c;
    c.x = (a.x + b.x) / 2;
    c.y = (a.y + b.y) / 2;
    
    return c;
}



// bài 4
struct a
    {
        int age;
        string fname;
        string sname;
        int sos;
    } ;
int main ()
{
    
    // bài 1
    point p;
    cin >> p.x >> p.y;
    print (p);
    
    
    
    // bài 3
    point y, z;
    cinpoint (y);
    cinpoint (z);
    point c = midpoint (y, z);
    print (c);
    
    
    
    // bài 4:
    a b;
        cin >> b.age >> b.fname >> b.sname >> b.sos;
        cout << b.age << " " << b.fname << " " << b.sname << " " << b.sos;
}

