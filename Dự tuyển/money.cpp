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

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, a[30], res, x[30];
vector<vector<int>> ans;
vi temp;
void check() {
    ll anh = 0, em = 0;
    for(int i = 1; i <= n; i++) {
        if(x[i])
            anh += a[i];
        else 
            em += a[i];
    }
    if(anh == em) {
        temp.clear();
        for(int i = 1; i <= n; i++) {
            temp.eb(x[i]);
        }
        ans.eb(temp);
    }
}
void tim(int i) {
    for(int j = 0; j <= 1; j++) {
        x[i] = j;
        if(i == n)
            check();
        else 
            tim(i+1);
    }
}
void solve(){
    if(res%2 != 0) {
        cout << "NO";
        return;
    }
    tim(1);
    if(ans.empty()) {
        cout << "NO";
        return;
    }
    for(vi i : ans) {
        for(int j : i) {
            if(!j)
                cout << "A ";
            else 
                cout << "B ";
        }
        cout << '\n';
    }
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        res += a[i];
    }
}
#define task "money"
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