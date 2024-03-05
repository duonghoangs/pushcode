
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
   
    string s_1 = "a"; cout << s_1 << " ";
    string s_2 = "b"; cout << s_2 << " ";
    string s;
    for (int i = 0; i < 9; ++i)
    {
        s = s_2 + s_1;
        cout << s << " ";
        string s0;
        s0 = s_2;
        s_2 = s;
        s_1 = s0;
    }
    return 0;
}

