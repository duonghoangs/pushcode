#include <iostream>
#include <vector>

using namespace std;
bool test (long long int n)
{
    vector<long long int> a;
    while (n > 0)
    {
        int z = n % 10;
        n /= 10;
        a.push_back(z);
    }
    int i = a.size();
    int m = i - 1;
    for (int j = 0; j < i / 2; ++j)
    {
        if (a[j] != a[m]) {return false;}
        --m;
    }
    return true;
}



int main ()
{
int t;
cin >> t;
for (int i = 0; i < t; ++i)
{
    int a[2];
    cin >> a[0] >> a[1];
    int sum = 0;
    for (int i = a[0]; i <= a[1]; ++i)
    {
        if (test(i)) {++sum;}
    }
    cout << sum;

}
}

