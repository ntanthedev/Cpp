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

const int N = 1e3+10;
const ll MOD = 1e9+7;

ll n, k, ans = 1;
ll a[N][N], b[N], flag;
bool check[N][N][11];
void solve(){
    //memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; i++){
        flag = 1;
        for(int j = i; j >= 1; j--){
            for(int f = 2; f <= k; f++){
                if(!check[j][i][f]){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                b[i]++;
            else 
                break;
        }
    }
    //for(int i = 1; i <= n; i++)
        //cout << b[i] << " ";
    cout << *max_element(b+1, b+1+n);
}

void init(){
    cin >> n >> k;
    for(int j = 1; j <= k; j++){
        for(int i = 1; i <= n; i++){
            cin >> a[j][i];
            for(int f = 1; f <= i; f++){
                check[f][i][j] = 1;
            }
        }
    }
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
