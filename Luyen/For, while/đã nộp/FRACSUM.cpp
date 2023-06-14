#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("FRACSUM.inp");
    xuat.open("FRACSUM.out");
    long long a, b, c, d, x, y, r, i, j;
    doc>>a>>b>>c>>d;
    y = d*b;
    x = (a*(y/b)) + (c*(y/d));
    i = x; j = y;
    while(j != 0)
    {
        r = i%j;
        i = j;
        j = r;
    }
    // i = gcd(y,x)
    y /= i;
    x /= i;
    xuat<<x<<" "<<y;
    doc.close();
    xuat.close();
}
