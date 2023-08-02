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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n;
vll a, b;

ll sqr(ll x) {
	return x*x;
}
bool is_prime[10000009];
const int Max_Sang = 10000009;
void sang_eratosthene() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 2; i <= sqrt(Max_Sang); i++)
		if(is_prime[i]) {
			for(auto j : b) {
				if(sqr(j) * sqr(i) <= n)
					a.eb(sqr(j) * sqr(i));
				else 
					break;
			}
			b.eb(i);
			if(pow(i, 8) <= n)
				a.eb(pow(i, 8));
			for(int j = i*i; j <= Max_Sang; j += i)
				is_prime[j] = false;
		}
}

void solve() {
	sang_eratosthene();
	sort(all(a));
	//dbg(b);
	a.eb(LLONG_MAX);
	// cout << a.size() << '\n';
	for(int i = 0; i < a.size(); i++) {
		// cout << a[i] << " " ;
		if(a[i] > n) {
			cout << i;
			return;
		}
	}
	
}

void init() {
	cin >> n;
}
#define task ""
int32_t main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	if(fopen(task".inp","r")) {
		freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	}
	int test_case = 1;
	//cin >> test_case;
	while(test_case--) {
		init();
		solve();
	}
}