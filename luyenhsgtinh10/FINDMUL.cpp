#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll m, a, b, n;
void solve(){
    if(a < b)
        swap(a, b);
    cout<<"a: "<<a<<"\nb: "<<b<<'\n'<<"ans: ";
    long long c=a/ b, d=n%c, e=(n-d)/c;
    if(d==0) cout<<n/c*a;
    if(d!=0) cout<<(e+d-1)*b;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("a.inp","r",stdin);
    // freopen("a.out","w",stdout);
    cin >> a >> b >> n;
    solve();
}