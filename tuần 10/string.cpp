
#include <iostream>
using namespace std;

int size (const char* a)
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; ++i)
    {
        ++count;
    }
    return count;
}

char* returnb(const char* a)
{
    char* b = new char [size(a) + 1];
    for (int i = 0; i < size(a); ++i)
    {
        b[i] = a[i];
    }
    return b;
}
char* delete_char(const char* a, const char c)
{
    int s = 0;
    char* b = new char[s + 1];
    for (int i = 0; i < size(a); ++i)
    {
        if (a[i] != c) {b[s] = a[i]; ++s;}
    }
    
    return b;
    
}

char* pad_right(const char* a, int n)
{
    if (size(a) >= n) {return returnb(a);}
    char* b = new char[n + 1];
    {
        for (int i = 0; i < n; ++i)
        {
            if (i < size(a)) {b[i] = a[i];}
            else {b[i] = '0';}
        }
    }
    return b;
}
char* pad_left(const char* a, int n)
{
    if (size(a) >= n)
    {
        return returnb(a);
    }
    char* b = new char[n + 1];
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i < n - size(a)) {b[i] = '0';}
        else
        {
            b[i] = a[x]; ++x;
        }
    }
    return b;
}

char* truncate(const char* a, int n)
{
    if (size(a) <= n) {return returnb(a);}
    char* c = new char [n + 1];
    for (int i = 0; i < n; ++i)
    {
        c[i] = a[i];
    }
    c[n] = '\0';
    return c;
}


bool is_palindrome(const char* a)
{
    for (int i = 0; i < size(a) / 2; ++i)
    {
        if (a[i] != a[size(a) - 1 - i]) {return false;}
    }
    return true;
}

char* trim_left (const char* a)
{
    char* b = new char [size(a) + 1];
    int i = 0;
    int x = 0;
    while (a[i] == ' ') {++i;}
    for (; i < size(a); ++i)
    {
        b[x] = a[i];
        ++x;
    }
    b[x + 1] = NULL;
    return b;
}
char* trim_right (const char * a)
{
    char* b = new char [size(a) + 1];
    int i = size(a);
    int x = 0;
    while (a[i - 1] == ' ') {--i;}
    while (x < i)
    {
        b[x] = a[x];
        ++x;
    }
    b[x + 1] = NULL;
    return b;
}
int main ()
{
    const char* a = "   hihiha ha     ";
    cout << size(a);
    cout << delete_char(a, 'i') << endl;
    cout << pad_right(a, 8) << endl;
    cout << pad_left(a, 9) << endl;
    cout << truncate(a, 5) << endl;
    cout << is_palindrome(a) << endl;
    cout << trim_left(a) << endl;
    cout << trim_right(a);
}

