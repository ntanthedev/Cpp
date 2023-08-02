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

const int N = 2e6+10;
const ll MOD = 1e9+7;

ll n, a[N], x, y, z, X[N], Y[N], Z[N], ans = 0;

void solve() {
	Z[n+1] = 0;
	for(int i = n; i >= 1; i--) {
		Z[i] = Z[i+1];
		Y[i] = Y[i+1];
		X[i] = X[i+1];
		if(a[i] == z)
			Z[i]++;
		if(a[i] == y) 
			Y[i] += Z[i+1];
		if(a[i] == x)
			X[i] += Y[i+1];
	}
	cout << X[1] ;//<< " " << Y[1] << " " << Z[1];
}


void init() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> x >> y >> z;
}
#define task "CHONTR"
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