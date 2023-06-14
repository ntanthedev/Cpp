#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("SD.inp");
    xuat.open("SD.out");
    unsigned long long n, S = 0, i = 1;
    doc>>n;
    do{
        if(n%i == 0)
        {
            S += i;
        }
        i++;
    }while(i <= n);
    xuat<<S;
    doc.close();
    xuat.close();
}
