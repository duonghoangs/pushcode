
#include <iostream>
#include <stdlib.h>
using namespace std;
int randr (int n)
{
    srand(static_cast<unsigned int>(std::time(nullptr)));    return rand() % n;
}


int main ()
{
    
    int n;
    cin >> n;
    cout << randr (n);
}
