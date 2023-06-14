#include<bits/stdc++.h>
unsigned long long a,b,c,d;
using namespace std;
long long demuoc(long long x, long long y, long long z)
{
    long long A, B, C;
    A = x/y;
    B = x/z;
    C = x/(__gcd(y,z));
    return A+B-C;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("CNTNUM.inp","r",stdin);
    //freopen("CNTNUM.out","w",stdout);
    cin>>a>>b>>c>>d;
    long long X;
    X = demuoc(b,c,d) - demuoc(a-1,c,d);
    cout<<(b-a+1)-X;
}
