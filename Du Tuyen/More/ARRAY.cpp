#include<bits/stdc++.h>
#define tag "ARRAY"
#define ll long long 
#define pb push_back
const int N = 1e6+9;
using namespace std;
ll n, C, a[N];
string x, y, s;
unordered_map<int, ll> M;
void solve(){
    ll ans = 0, res = 0, l = 1, r = 1;
    //bool flag = true;
    M[a[r]]++;
    while(l <= r && r <= n){
        if(a[r] == 1)
            res += M[2];
        if(a[r] == 2)
            res += M[1];
        if(res > C){
            l++;
            if(a[l] == 1)
                res -= M[2];
            else
                res -= M[1];
            M[a[l]]--;
            //flag = false;;
        }
        else{
            ans = max(ans, r-l+1);
            r++;
            M[a[r]]++;
        }
    }
    //cout<<x<<" "<<y<<'\n';
    //for(int i = 1; i <= n; i++)
        //cout<<a[i]<<" ";
    //cout<<'\n'<<ans;
    cout<<ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> C >> x >> y;
    for(int i = 1; i <= n; i++){
        cin >> s;//cout<<s<<" ";
        if(s == x)
            a[i] = 1;
        else if(s == y)
            a[i] = 2;
        else
            a[i] = 0;
    }
    solve();
}