//Written by: ntannn_
//created in 01:46:18 - Mon 10/06/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

ll n, a[N], suf[N][3], pre[N], ans = 0;
string s;

void solve() {
    for(int j = 0; j < 3; j++) 
        suf[n + 1][j] = 0;
    
    for(int i = n; i >= 1; i--) 
        for(int j = 0; j < 3; j++) 
            suf[i][j] = suf[i + 1][j] + ((pre[n] - pre[i - 1] + 3) % 3 == j); 
    
    for(int i = 1; i <= n; i++) 
        cout << pre[i] << " "; cout << '\n';
    
    for(int j = 0; j < 3; j++, cout << '\n')
        for(int i = 1; i <= n; i++)
            cout << suf[i][j] << " ";

    for(int i = 0; i < n; i++) {
        // ans += (pre[i] % 3 == 0);
        ans += (suf[i + 2][(3 - pre[i]) % 3]);
    }

    ans += suf[1][0];

    cout << ans;
}

void init() {
    cin >> s;
    pre[0] = 0;
    n = s.size();
    s = ' ' + s;
    for(int i = 1; i <= n; i++) {
        a[i] = s[i] - '0';
        pre[i] = pre[i - 1] + a[i];
        pre[i] %= 3;
    }
}

#define task "CAU3"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
// #include <bits/stdc++.h>
// #define fi first 
// #define se second 
// using namespace std;
// typedef long long ll;
// vector<ll>save,nt(9000021);
// void solve()
// {
//     ll m,n,k;
//     cin>>m>>n>>k;
//     string x,y;
//     cin>>x>>y;
//     set<string>st,stt;
//     for(ll i=0;i<(1<<(x.size()));i++)
//     {
//         if(__builtin_popcount(i)!=n) continue;
//         string xx;
//         for(ll j=0;j<x.size();j++)
//         {
//             if(i&(1<<j))
//             {
//                 xx.push_back(x[j-1]);
//             }
//         }
//         st.insert(xx);
//     }
//     for(ll i=0;i<(1<<(y.size()));i++)
//     {
//         if(__builtin_popcount(i)!=n) continue;
//         string xx;
//         for(ll j=0;j<y.size();j++)
//         {
//             if(i&(1<<j))
//             {
//                 xx.push_back(y[j-1]);
//             }
//         }
//         stt.insert(xx);
//     }
//     map<string,ll>M;
//     ll d=1;
//     for(auto xx:st)
//     {
//         //cout<<xx<<" ";
//         M[xx]=d;
//         d++;
//     }
//     while(m--)
//     {
//         string t;
//         cin>>t;
//         if(stt.count(t) || !st.count(t)) cout<<-1<<'\n';
//         else cout<<(M[t]%k)<<'\n';
//     }
    

// }
// int32_t main() {
//     ios::sync_with_stdio(0), cin.tie(0);
//     solve();
    
// }