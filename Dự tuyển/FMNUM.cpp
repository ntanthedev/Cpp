#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll n, s, c9, ct, res = 1;
void solve(){
    c9 = s/9;
    if(n - c9 > 1)
        ct = n - 1 - c9;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("FMNUM.inp","r",stdin);
    //freopen("FMNUM.out","w",stdout);
    cin >> n >> s;
    solve();
}
