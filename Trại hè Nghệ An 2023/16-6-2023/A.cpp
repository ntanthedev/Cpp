#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
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

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 5e3+10;
const ll MOD = 1e9+7;

ll n, a[N], ans = 0;
ll s[N];
umll M;
void solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(M[a[i] - a[j]] < i && M[a[i] - a[j]] != 0){
                ans++;
                break;
                //cout << i << " " << j << " " << M[a[i] - a[j]] << '\n';
            }
        }
        for(int j = 1; j <= i; j++){
            if(M[a[i] + a[j]] == 0)
                M[a[i] + a[j]] = i;
        }
    }
    cout << ans;
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    M[a[1]] = 1;
}
#define task ""
int32_t main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        init();
        solve();
    }
}