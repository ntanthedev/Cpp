#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream doc;
    ofstream xuat;
    doc.open("LCM.inp");
    xuat.open("LCM.out");
    unsigned long long a, b, t, m;
    doc>>a>>b;
    m = a > b? a : b;
    t = m;
    do{
        if(m%a == 0 && m%b == 0)
        {

           break;
        }
        m += t;
    } while(true);
    xuat<<m;
    doc.close();
    xuat.close();
}
