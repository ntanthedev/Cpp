#include<bits/stdc++.h>
#define tag "tag"
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define po pop_back
#define ll long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
using namespace std;
ll n, x, d = 0, l, r;
unordered_map<ll, ll> M;

void solve(){
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n; l = 0, r = 0;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x > 0) d++;
        if(x < 0) d--;
        if(M[d] == 0 && d != 0)
            M[d] = i;
        else{
            if(i - M[d] >= r - l){
                r = i;
                l = M[d];
            }
        }
    }
    cout<<l+1<<" "<<r;
    //solve();
}