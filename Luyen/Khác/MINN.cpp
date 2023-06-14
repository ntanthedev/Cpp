#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
    ifstream doc;
    ofstream xuat;
    doc.open("MINN.inp");
    xuat.open("MINN.out");
    long long n, m, x;
    doc>>n>>m;
    x = n;
    while(x%m != 0)
    {
        if (x%m == 0)
            break;
        else
            x++;

    }
    xuat<<x;
    doc.close();
    xuat.close();
}
