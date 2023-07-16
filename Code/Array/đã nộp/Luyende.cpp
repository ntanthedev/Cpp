#include<bits/stdc++.h> // luyen bai so THMANG
using namespace std;
unsigned long long a[1000009], b[1000009], n;

bool nt(long long x)
{
    if(x < 2)
        return 0;
    for(int i = 1; i <= sqrt(x); i++)
        if(x%i == 0)
            return 0;
    return 1;
}

int main ()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        {
            cin>>a[i];
            b[i] = a[i];
        }
    //dong 1
    sort(b + 1, b + 1 + n, greater<int>());
    for(int i = 1; i <= n; ++i)
        cout<<b[i];
    cout<<'\n';
    //dong 2
    for(int i = 1; i <= n; ++i)
        if(nt(a[i]) == 1)
            cout<<a[i];
    cout<<'\n';
    //dong 3
    long long Sc = 0, S = 0, dem = 0;
    for(int i = 1; i <= n; ++i)
        if(a[i]%2 == 0)
            Sc += a[i];
    cout<<Sc<<'\n';
    //dong 4
    for(int i = 1; i <= n; ++i)
        {
            S += a[i];
            dem += 1;
        }
    cout<<fixed<<setprecision(2);
    cout<<(double)S/dem<<'\n';
    //dong 5
    for(int i = 1; i <= n; ++i)
        cout<<b[i];

}
