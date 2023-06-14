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
ll n, ans = 0;
ii a[N];
queue<int> q;
// int read(){
//     bool neg = false;
//     char c = getchar();
//     for(; '0' > c || '9' < c; c = getchar())
//         if(c == '-')
//             neg = !neg;
//     int k = 0;
//     while('0' <= c && c <= '9')
//         k = (k << 3) + (k << 1) + c - '0', c = getchar();
//     return k;
// }
bool cmp(ii x, ii y){
    return(x.fi < y.fi || (x.fi == y.fi && x.se < y.se));
}
void solve(){
    sort(a+1, a+1+n, cmp);
    q.push(a[1].se);
    for(int i = 2; i <= n; i++){
        while(!q.empty() && q.front() <= a[i].fi)
            q.pop();
        q.push(a[i].se);
        ans = max(ans, (ll)q.size());
    }
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    solve();
}