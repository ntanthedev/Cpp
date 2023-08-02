#include<bits/stdc++.h>
#define ll long long
#define xau "game"
const int N = 1e6+9;
using namespace std;
unordered_map<ll, ll>M;
ll n, T, x, d = 0;
void solve(){
    cin >> T;
    while(T--){
        cin >> x;
        if(M[x] == 0){
            cout<<-1<<'\n';
            d--;
        }
        else{
            cout<<M[x]<<'\n';
            d++;
        }
    }
    if(d > 0)
        cout<<1;
    else if(d == 0)
        cout<<0;
    else
        cout<<-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(M[x] == 0)
            M[x] = i;
    }
    solve();
}


