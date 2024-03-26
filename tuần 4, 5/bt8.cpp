#include <iostream>
using namespace std;
void pupplesort (int* a, int n, int* benhnhan)
{
    for (int i = 0; i < n; ++i)
    {
        
        for (int j = i; j < n; ++j)
        {
            if (a[i] > a[j])
            {
                swap (a[i], a[j]);
                swap (benhnhan[i], benhnhan[j]);
            }
        }
    }
}
int main ()
{
    int n;
    cin >> n;
    int a[n];
    int nguoi = 1;
    int benhnhan[n];
    for (int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        a[i] = t;
        benhnhan[i] = nguoi; ++nguoi;
    }
    pupplesort (a, n, benhnhan);
    int time = 0;
    cout << "thứ tự khám: ";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            time += a[i];
        }
        cout << benhnhan[i] << " ";
    }
    cout << endl <<"tổng thời gian tối thiểu: " << time;
}


