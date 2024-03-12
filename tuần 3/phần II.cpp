#include <iostream>

using namespace std;


struct point
{
    double x, y;
};


// bài 5
struct rect
{
    int x, y, w, h;
    bool contain (const point p)
    {
        if (p.x < x || p.y < y){return false;}
        if (p.x > x + w || p.y > y + h) {return false;}
        return true;
    }
};
void cinrect (rect r)
{
    cin >> r.x >> r.y >> r.w >> r.h;
}
void cinpoint (point p)
{
    cin >> p.x >> p.y;
}



// bài 6
struct ship
{
    string id;
    rect ships;
    int dx, dy;
    void move (rect &ships)
    {
        ships.x += dx;
        ships.y += dy;
    }
};
void cinship (ship& s)
{
    cin >> s.id >> s.ships.x >> s.ships.y >> s.dx >> s.dy;
}



// bài 7
void display (const ship& s)
{
    cout << "(x,y) = " << "(" << s.ships.x << "," << s.ships.y << ")" << endl;
    cout << "số hiệu: " << s.id << endl;
}


int main ()
{
    ship s;
    cinship (s);
    
    int loop = 0;
    while(loop < 10)
    {
        s.move(s.ships);
        display (s);
        ++loop;
    }
    
}


