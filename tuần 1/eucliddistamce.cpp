//
//  main.cpp
//  main
//
//  Created by Thái Dương on 05/03/2024.
//

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    cout << sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
