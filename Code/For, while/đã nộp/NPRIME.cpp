#include<bits/stdc++.h>
using namespace std;
bool gnt(long long x)
{
    if(x < 2) return 0;
    long long i = 2, t = 0;
    while(i <= sqrt(x))
        {
            if(x%i == 0)
                t+= 1;
             if(t == 2) return 0;
        }
        if(t == 0) return 0;
    return 1;
}
int main()
{
    ifstream doc;
    ofstream xuat;
    doc.open("NPRIME.inp");
    xuat.open("NPRIME.out");
    unsigned long long n, x, y;
    doc>>n;
    x = n;
    while(gnt(x) == 0)
        x--;
    y = (n - x) + n;
    while (gnt(y) == 0)
        {
            if(y == n)
            {
                y = x + n;
                break;
            }
            y--;
        }
    if((y - n) >= (n - x))
        xuat<<x;
    else
        xuat<<y;
    doc.close();
    xuat.close();
}
