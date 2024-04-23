#include <iostream>
using namespace std;

struct String
{
    int n;
    char* str;
    String (const char* s)
    {
        n = strlen(s);
        str = new char [n + 1];
        for (int i = 0; i < n; ++i)
        {
            str[i] = s[i];
        }
    }
    ~String ()
    {
        delete[] str;
    }
    
    void print ()
    {
        cout << str;
    }
    
    void append (const char* x)
    {
        int size = strlen(x);
        char* temp = new char [n + size + 1];
        
        for (int i = 0; i < size + n; ++i)
        {
            if (i < n) {temp[i] = str[i];}
            else {temp[i] = x[i - n];}
        }
        str = temp;
        delete[] temp;
    }
};



int main ()
{
    String s = ("string");
    s.append(" hi");
    s.print();
    
}
