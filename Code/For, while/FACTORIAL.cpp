#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("FACTORIAL.inp");
    xuat.open("FACTORIAL.out");
    long long n, gt = 1;
    doc>>n;
    for(int i = 1; i <= n; i++)
    {
        gt = (gt * (i%123456789))%123456789;
    }
    xuat<<gt;
    doc.close();
    xuat.close();
}
