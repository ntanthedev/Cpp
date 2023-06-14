#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DEMGACH.inp","r",stdin);
    freopen("DEMGACH.out","w",stdout);
    unsigned long long r, d, S, X, T;
    cin>>r>>d;
    S = r*d;
    X = ((r - 2)*2)+(d*2);
    T = S - X;
    cout<<X<<" "<<T;
}
