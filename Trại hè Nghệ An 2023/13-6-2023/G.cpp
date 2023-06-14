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

const int N = 1e6+10;
const ll MOD = 1e9+7;
stack<int> st;
string s;
ll gmax = 0, gmin = 0, n, ld, nt = 0, ns = 0;
umll M;
void solve(){
    s = ' ' + s;
    n = s.size()-1;
    ll d = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '('){
            d++;
            st.push(1);
        }
        else{
            if(st.size() > 0)
                st.push(d);
            d--;
        }
        if(!M[d] && d != 0)
            M[d] = i;
        else
            ld = max(ld, i - M[d]);
    }
    d = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '(')
            d++;
        else 
            d--;
        gmax = max(gmax, abs(d));
    }
    //cout << gmax;
    cout << max(1LL, ld/2) << " " << gmax;
}

void init(){
    cin >> s;
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