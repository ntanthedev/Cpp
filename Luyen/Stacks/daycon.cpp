#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e3+9;
ll n, gmax = 0, cs = 1;
deque<ll>dq;
vector<ll> L(N, 1), T(N, 1), a(N);
void solve(){
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[j] < a[i] && L[i] < L[j]+1){
                L[i] = L[j]+1;
                T[i] = j;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(L[i] > gmax){
            gmax = L[i];
            cs = i;
        }
    }
    cout<<gmax<<'\n';
    int j = cs;
    T[1] = 0;
    while(j != 0){
        dq.push_back(a[j]);
        j = T[j];
    }
    while(!dq.empty()){
        cout<<dq.back()<<" ";
        dq.pop_back();
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("daycon.inp","r",stdin);
    freopen("daycon.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solve();
}