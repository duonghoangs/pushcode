#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int* randarr ()
{
    int *a;
    srand(time(NULL));
    for (int i = 0; i < 50; ++i)
    {
        a[i] = rand() % 50;
    }
    return a;
}
void boba (int *a)
{
    for (int i = 0; i < 50 - 2; ++i) 
    {
        for (int j = i + 1; j < 50 - 1; ++j)
        {
            for (int k = j + 1; k < 50; ++k)
            {
                int sum = a[i] + a[j] + a[k];
                if (sum % 25 == 0)
                {
                    cout << "(" << a[i] << ", " << a[j] << ", " << a[k] << ")" << endl;
                }
            }
        }
    }
}
int main ()
{
    int* a = randarr ();
    boba (a);
    
}
