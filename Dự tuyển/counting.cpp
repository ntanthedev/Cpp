#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll n, dem = 0;
unordered_map<ll, bool>M;
void solve(){
    for(int i = 1; i <= n; i++){
        M[i*i] = true;
    }
    for(int i = 1; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k <= n; k++){
                if(M[i*k] && M[i*j] && M[j*k])
                    dem++;
            }
        }
    }
    cout<<dem;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen("counting.inp","r")){
        freopen("counting.inp","r",stdin);
        freopen("counting.out","w",stdout);
    }
    cin >> n;
    solve();
}

