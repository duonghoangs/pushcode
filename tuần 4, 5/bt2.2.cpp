
#include <iostream>

using namespace std;
int main ()
{
    
    int tongchan = 0;
    int sole = 0;
    int max = -100000;
    int min = 100000;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a > max) {max = a;}
        if (a < min) {min = a;}
        if (a % 2 == 0) {tongchan += a;}
        else {sole += 1;}
    }
    
    cout << max << " " << min << " " << tongchan << " " << sole;
}
