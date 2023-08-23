/*--------------------POI--------------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int T = 1e9 + 7;

void read_file(string file, bool read = 1, bool write = 1) {
	string fileinp = file + ".INP", fileout = file + ".OUT";
	const char* INP = fileinp.c_str();
	const char* OUT = fileout.c_str();
	if(read) freopen(INP, "r", stdin);
	if(write) freopen(OUT, "w", stdout);
}

const int N = 1e3 + 5;
string s;
int n, ans = 0;
ll dp[N][N];

void Backtracking(int i, int d = 0, int max_d = 0) {
	if(i == n) {
		if(d == 0) {
			ans = max(ans, max_d);
			dp[i][d] = max(dp[i][d], (ll)max_d);
		}
		return ;
	}
	if(dp[i][d] != -1) return ;
	dp[i][d] = 0;
	if(s[i] ==  '(' || s[i] == '?') if(d <= n - i) {
		Backtracking(i + 1, d + 1, max(max_d, d + 1));
		dp[i][d] = max(dp[i][d], dp[i+1][d+1]);
	}
	if(s[i] == ')' || s[i] == '?') if(d > 0) {
		Backtracking(i + 1, d - 1, max(max_d, d - 1));
		dp[i][d] = max(dp[i][d], dp[i+1][d-1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	read_file("BTN1");
	memset(dp, -1, sizeof(dp));
	cin >> s;
	n = (int)s.size();
	Backtracking(0);
	cout << ans << "\n";
	return 0;
}