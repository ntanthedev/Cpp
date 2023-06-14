#include<bits/stdc++.h>
using namespace std;
long long tonguoc(long long x)
{
        long long i = 1, s = 0, j;
        while (i <= sqrt(x))
        {
            if (x%i == 0)
            {
                j = x/i;
                s += i;
                if(i != j)
                    s += j;

            }
            i++;
        }
        return s;
}
int main ()
{
    ifstream doc;
    ofstream xuat;
    doc.open("FRIENDS.inp");
    xuat.open("FRIENDS.out");
    long long n, a, b;
    doc>>n;
    for(int i = 1; i <= n; i++)
    {
        doc>>a>>b;
        if(tonguoc(a)-a == b && tonguoc(b)-b == a)
            xuat<<"YES"<<endl;
        else
            xuat<<"NO"<<endl;
    }
    doc.close();
    xuat.close();
}
