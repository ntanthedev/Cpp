#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll a, n;
unordered_map<int, ll>M;
void solve(){
    for(int i = a; i <= n; ++i){
        int t = i;
        while(t != 0){
            M[t%10]++; //cout<<t%10<<" "<<M[t%10]<<'\n';
            t /= 10;
        }
    }
    for(int i = 0; i <= 9; i++){
        cout<<M[i]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("trangsach.inp","r",stdin);
    freopen("trangsach.out","w",stdout);
    cin >> n >> a;
    solve();
}
