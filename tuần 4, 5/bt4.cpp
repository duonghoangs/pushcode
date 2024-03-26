

#include <iostream>
#include <vector>
using namespace std;


int main() {
    int m, n;
    cin >> m >> n;
    
    char a[m][n];
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            
            if (a[i][j] != '*')
            {
                int sum = 0;
                if (a[i + 1][j + 1] == '*' and i + 1 < m and j + 1 < n) {sum++;}
                if (a[i + 1][j] == '*' and i + 1 < m) {sum++;}
                if (a[i + 1][j - 1] == '*' and i + 1 < m and j - 1 >= 0) {sum++;}
                if (a[i - 1][j - 1] == '*' and i - 1 >= 0 and j - 1 >= 0) {sum++;}
                if (a[i - 1][j] == '*' and i - 1 >= 0) {sum++;}
                if (a[i - 1][j + 1] == '*' and i - 1 >= 0 and j + 1 < n) {sum++;}
                if (a[i][j - 1] == '*' and j - 1 >= 0) {sum++;}
                if (a[i][j + 1] == '*' and j + 1 < n) {sum++;}
                cout << sum << " ";
            }
            else {cout << a[i][j] << " ";}
        }
        cout << endl;
    }
   
}
