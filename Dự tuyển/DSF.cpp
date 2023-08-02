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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e5+10;
const ll MOD = 1e9+7;

int par[N], n, m, ans;
vi f[N];

int find_set(int x) {
	return par[x] < 0 ? x : par[x] = find_set(par[x]); 
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if(a != b) {
		if(par[a] > par[b])
			swap(a, b);
		par[a] += par[b];
		par[b] = a;
		ans--;
	}
}

void solve() {

}

void init() {
	memset(par, -1, sizeof(par));
	cin >> n >> m; 
	ans = n;
	while(m--) {
		int u, v;
		cin >> u >> v;	
		union_sets(u, v);
		cout << ans << '\n';
	}
}
#define task "DSF"
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