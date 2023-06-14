#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

using namespace std;

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    } 
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+7;

bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//----------------------------
ll n, a[N], l, r, x[41];
bool flag = 0, flags5 = 1, flags4 = 1;
ll c[N], pod = 0;
//----------------------------
ll t1, t2;
vll ans;
void check1(){
    ll res = 0;
    for(int i = 1; i <= (n >> 1); i++)
        res += x[i]*a[i];
    if(res <= r)
        c[++pod] = res;
}
void check2(){
    ll res = 0;
    for(int i = (n >> 1)+1; i <= n; i++)
        res += x[i]*a[i];
    sort(c+1, c+1+pod);
    ll t = upper_bound(c+1, c+1+pod, r - res) - c - 1;
    if(t > pod) return;
    if(c[t] + res >= l && ans.empty()){
        t1 = c[t], t2 = res;
        //ans.clear();
        for(int i = (n >> 1)+1; i <= n; i++)
            if(x[i]) ans.eb(i);
        //flag = 1;
    }
}
void tim1(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == (n >> 1))
            check1();
        else
            tim1(i+1);
    }
}
void tim2(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n)
            check2();
        else
            tim2(i+1);
    }
}
void tim3(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == (n >> 1)){
            ll res = 0;
            for(int k = 1; k <= (n >> 1); k++)
                res += x[k]*a[k];
            if(res == t1){
                for(int k = 1; k <= (n >> 1); k++)
                    if(x[k]) ans.eb(k);
                flag = 1;
            }
        }
        else 
            tim3(i+1);
        if(flag)
            return;
    }
}
void sub12(){
    tim1(1);
    tim2((n >> 1) + 1);
    if(!ans.empty()){
        tim3(1);
        sort(all(ans));
        cout << ans.size() << '\n';
        for(int i : ans)
            cout << i << " ";
    }
    else
        cout << -1;
}
ll L[N], par[N], S = 0;
void sub3(){
    for(int i = 1; i <= n; i++)
        L[i] = 0, par[i] = 0;
    L[0] = 1;
    for(int i = 0; i <= n; i++) 
        S += a[i];
    for(int i = 1; i <= n; i++){
        for(int j = S; j >= a[i]; j--)
            if(L[j - a[i]] == 1 && L[j] == 0){
                L[j] = 1;
                par[j] = i;
            }
    }
    for(int i = l; i <= r; i++){
        if(L[i] == 1){
            S = i;
            while(par[S] != 0){
                ans.eb(par[S]);
                S -= a[par[S]];
            }
            break;
        }
    }
    cout << ans.size() << '\n';
    for(int i : ans)
        cout << i << " ";
}
void sub4(){
    ll sum = 0, i = 0;
    while(sum < l){
        sum += a[++i];
    }
    if(sum > r)
        cout << -1;
    else{
        cout << i << '\n';
        for(int j = 1; j <= i; j++)
            cout << j << " " ;
    }
}
void sub5(){
    if(n*(n+1)/2 < l){
        cout<<-1;
        return;
    }
    ll i = n;
    ll sum=l;
    if(sum<=i){
        cout<<sum;
        return;
    }
    while(sum>i){
        sum-=i;
        ans.pb(i);
        i--;
    }

    if(sum>0)ans.pb(sum);
    reverse(all(ans));
    cout << ans.size() << '\n';
    for(auto i : ans)
        cout << i << " ";
}
pll b[N];
void sub6(){
    sort(b+1, b+1+n);
    ll i = 1, j = n, s1 = 0, s2 = 0, k = 0;
    while(i <= j){
        s1 += b[i].fi;
        s2 += b[j].fi;
        if(s2 < l){
            j++;
            break;
        }
        if(s1 > r){
            i--;
            break;
        }
        k = i;
        i++;
        j--;
    }
    ll s = 0;
    for( i = 1; i <= k; i++)
        s += b[i].fi;
    i = 1;
    while(s < l){
        i++, k++;
        s -= b[i].fi;
        s += b[k].fi;
    }
    if(s > r)
        cout << -1;
    else{
        cout << k-i+1 << '\n';
        for(; i <= k; i++)
            cout << b[i].se <<" " ;
    }
}
void solve(){
    if(n <= 40)
       sub12();
    else if(n <= 80)
        sub3();
    else if(flags4)
        sub4();
    else if(flags5)
        sub5();
    else 
        sub6();
}
void init(){
    read(n), read(l), read(r);
    for(int i = 1; i <= n; i++){
        read(a[i]);
        if(i>=2 && a[i]!=a[i-1])
            flags4 = 0;
        if(i != a[i])
            flags5 = 0;
        b[i].fi = a[i], b[i].se = i;
    }
}
//-----TASK----------
#define task "TASK"
//-------------------
int32_t main(){
    //---------------------------------
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    //---------------------------------
    init();
    solve();
}
