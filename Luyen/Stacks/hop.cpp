#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e3+9;
ll cs = 0, n, gmax = 0;
vector<ll>L(N, 1), T(N, 1);
deque<ll> dq;
struct pt
{
    /* data */
    ll x, y;
};
pt a[N];
bool cmp(pt m, pt n){
    return (m.y < n.y || (m.y == n.y && m.x < n.x));
}

void solve(){
    sort(a+1, a+1+n, cmp);
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[j].y < a[i].x && L[i] < L[j]+1){
                L[i] = L[j] + 1;
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
        dq.push_back(a[j].y);
        dq.push_back(a[j].x);
        j = T[j];
    }
    int flag = 1;
    while(!dq.empty()){
        cout<<dq.back()<<" ";
        flag++;
        if(flag%2 != 0)
            cout<<'\n';
        dq.pop_back();
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("hop.inp","r",stdin);
    freopen("hop.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].x>>a[i].y;
    }
    solve();
}