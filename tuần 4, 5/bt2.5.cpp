#include <iostream>
#include <vector>
using namespace std;


void viet(vector <double>& diem, int n, int s, vector <int>& vt)
{
    for (int i = 0; i < s; ++i)
    {
        if (i % 3 == 0)
        {
            cout << endl;
            cout << "sinh vien " << vt[i / 3] << " : ";
        }
        cout << diem[i] << " ";
    }
}

void toan (vector <double>& diem, int s, int n, vector <int>& vt)
{
    for (int i = 0; i < s; i+=3)
    {
        for (int j = 0; j < s; j+=3)
        {
            if (diem[i] > diem[j])
            {
                swap (diem[i], diem[j]);
                swap (diem[i + 1], diem[j + 1]);
                swap (diem[i + 2], diem[j + 2]);
                swap (vt[i / 3], vt[j / 3]);
            }
        }
    }
    viet(diem, n, s, vt);
}

void li (vector <double>& diem, int s, int n, vector <int>& vt)
{
    for (int i = 1; i < s; i+=3)
    {
        for (int j = 1; j < s; j+=3)
        {
            if (diem[i] > diem[j])
            {
                swap (diem[i], diem[j]);
                swap (diem[i - 1], diem[j - 1]);
                swap (diem[i + 1], diem[j + 1]);
                swap (vt[i / 3], vt[j / 3]);
            }
        }
    }
    viet(diem, n, s, vt);
}

void tb (vector <double>& diem, int s, int n, vector <int>& vt)
{
    for (int i = 0; i < s; i+=3)
    {
        for (int j = 0; j < s; j+=3)
        {
            if ((diem[i] + diem[i + 1] + diem[i + 2]) / 3 > (diem[j] + diem[j + 1] + diem[j + 2]) / 3)
            {
                swap (diem[i], diem[j]);
                swap (diem[i + 1], diem[j + 1]);
                swap (diem[i + 2], diem[j + 2]);
                swap (vt[i / 3], vt[j / 3]);
            }
        }
    }
    viet(diem, n, s, vt);
    for (int i = 0; i < s; i+=3)
    {
        cout << (diem[i] + diem[i + 1] + diem[i + 2]) / 3 << " ";
    }
}


int main ()
{
    int n;
    cin >> n;
    vector <double> diem;
    vector <int> vt;
    for (int i = 0; i < n; ++i)
    {
        double toan, li, hoa;
        cin >> toan >> li >> hoa;
        diem.push_back(toan);
        diem.push_back(li);
        diem.push_back(hoa);
        vt.push_back(i + 1);
    }
    int s = diem.size();
    cout << endl << "theo toan";
    toan(diem, s, n, vt);
    cout << endl << "theo li";
    li(diem, s, n, vt);
    cout << endl << "theo diem tb";
    tb(diem, s, n, vt);
}
