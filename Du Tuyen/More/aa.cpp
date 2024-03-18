#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int T = 100000007;

void read_file(string file) {
	string fileinp = file + ".INP", fileout = file + ".OUT";
	const char* INP = fileinp.c_str();
	const char* OUT = fileout.c_str();
	freopen(INP, "r", stdin);
	freopen(OUT, "w", stdout);
}

const int MOD = 123456789;
const int N = 5005;
int n;
ll f[N][N];

ll Backtracking(int i, int j) {
	if(!i) return (j ? 0 : 1);
	if(f[i][j] != -1) return f[i][j];
	f[i][j] = 0;
	if(i > j)  f[i][j] += Backtracking(i - 1, j);
	else f[i][j] += Backtracking(i - 1, j) + Backtracking(i - 1, j - i);
	f[i][j] %= MOD;
	return f[i][j];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	read_file("IPARD");
	memset(f, -1, sizeof(f));
	cin >> n;
	cout << Backtracking(n, n) << "\n";
	return 0;
}