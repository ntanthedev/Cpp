#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define pp pair<int, int>
#define pb push_back
#define pbp(x, y) push_back(pp(x, y))
ll a, b;
int d[20], s;
ll dp[20][3][12][12];
void chuyen(ll a) {
    s = 0;
    while(a != 0) {
        s++;
        d[s] = a % 10 + 1;
        a /= 10;
    }
    reverse(d + 1, d + s + 1);
}

ll count(int length, int flag, int check1, int check2) {
    if(length == s + 1) {
        return 1;
    }
    if(dp[length][flag][check1][check2] != -1)
        return dp[length][flag][check1][check2];
    int limit = 10;
    if(flag == 0)
        limit = d[length];
    dp[length][flag][check1][check2] = 0;
    for(int i = 1; i <= limit; i++) {
        if(i == check1) {
            // cout<<i<<" "<<length<<" "<<check1<<" "<<check2<<endl;
            continue;
        }
        if(i == check2) {
            // cout<<i<<" "<<length<<" "<<check1<<" "<<check2<<endl;
            continue;
        }

        if(flag == 0 && i == d[length]) {
            dp[length][flag][check1][check2] += count(length + 1, 0, i, check1);
        } else {
            if(check1 == 0 && i == 1) {
                dp[length][flag][check1][check2] += count(length + 1, 1, 0, 0);
                continue;
            }
            dp[length][flag][check1][check2] += count(length + 1, 1, i, check1);
        }
    }
    return dp[length][flag][check1][check2];
}
ll solve(ll a) {
    ll gt = 0;
    chuyen(a);
    memset(dp, -1, sizeof(dp));
    gt += count(1, 0, 0, 0);
    return gt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("PFnum.inp", "r", stdin);
    freopen("PFnum.out", "w", stdout);
    cin >> a >> b;
    cout << solve(b) - solve(a - 1);
}

/*
#include <bits/stdc++.h>
using namespace std;

long long a, b, dp[20][2][20];

long long solve(int i, int tight, int prev, vector<int> digit, vector<int>&saving) {
    if (i == digit.size()) return 1;
    if (dp[i][tight][prev] != -1) return dp[i][tight][prev];

    int upp_bound = tight == 1 ? digit[i] : 9;
    long long res = 0;
    for (int d = 0; d <= upp_bound; ++d) {
        int newtight = tight & (d == upp_bound);
        saving[i] = d;
        if((d == saving[i - 2] && i > 1) || (d == saving[i - 1] && i > 0)) continue;
        res += solve(i + 1, newtight, d, digit, saving);
    }

    return dp[i][tight][prev] = res;
}

long long F(long long x) {
    vector<int> digit;
    vector<int> saving;

    saving.resize(18, 0);

    while(x != 0) {
        digit.push_back(x % 10);
        x /= 10;
    }
    reverse(digit.begin(), digit.end());
    memset(dp, -1, sizeof dp);

    return solve(0, 1, -1, digit, saving);
}
void ReadInput() {
    cin >> a >> b;
}
void solve() {
    cout << F(b) - F(a - 1);
}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("PFNUM.inp", "r", stdin);
    // freopen("PFNUM.out", "w", stdout);
    ReadInput();
    solve();

} 
*/
// #include <bits/stdc++.h>
// #define all(x) x.begin(), x.end()

// using namespace std;

// typedef long long ll;

// ll a, b, f[21][2][2][21][21];

// ll solve(int i, int d, bool ok, int pre1, int pre2, vector<int> s) {
//     if(i == s.size())
//         return 1;
//     if(f[i][d][ok][pre1][pre2] != -1)
//         return f[i][d][ok][pre1][pre2];

//     int k = d == 0 ? 9 : s[i];
//     ll res = 0;
//     for(int d = 0; d <= k; ++d) {
//         int dd = d & (d == k);
//         if((pre1 != d && pre2 != d)) {
//             int t;
//             if(!ok && d == 0)
//                 t = 10;
//             else
//                 t = d;
//             res += solve(i + 1, dd, ok || (d > 0), pre2, t, s);
//         }
//     }

//     return f[i][d][ok][pre1][pre2] = res;
// }

// ll cal(ll x) {
//     vector<int> s;

//     while(x != 0) {
//         s.push_back(x % 10);
//         x /= 10;
//     }

//     reverse(all(s));
//     memset(f, -1, sizeof(f));

//     return solve(0, 1, 0, -1, -1, s);
// }
// void innit() {
//     cin >> a >> b;
// }
// void solve() {
//     cout << cal(b) - cal(a - 1);
// }
// int main() {
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     freopen("PFNUM.inp", "r", stdin);
//     freopen("PFNUM.out", "w", stdout);
//     innit();
//     solve();
// }

/*
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n" 
#define pp pair<int,int>
#define pb push_back
#define pbp(x,y) push_back(pp(x,y))
ll a,b;
int d[20],s;
ll dp[20][3][12][12];
void chuyen(ll a)
    {s=0;
        while(a!=0)
            {
                s++;
                d[s]=a%10+1;
                a/=10;
            }
        reverse(d+1,d+s+1);
    }

ll count(int length,int flag,int check1,int check2)
    {
        if(length==s+1)
            {
                return 1;
            }
        if(dp[length][flag][check1][check2]!=-1)return dp[length][flag][check1][check2];
        int limit=10;
        if(flag==0)limit=d[length];
        dp[length][flag][check1][check2]=0;
        for(int i=1;i<=limit;i++)
            {
                if(i==check1)
                    {   
                        // cout<<i<<" "<<length<<" "<<check1<<" "<<check2<<endl;
                        continue;
                    }
                if(i==check2)
                    {   
                        // cout<<i<<" "<<length<<" "<<check1<<" "<<check2<<endl;
                        continue;
                    }

                if(flag==0&&i==d[length])
                    {
                        dp[length][flag][check1][check2]+=count(length+1,0,i,check1);
                    }
                else
                    {
                    if(check1==0&&i==1)
                    {
                        dp[length][flag][check1][check2]+=count(length+1,1,0,0);
                        continue;
                    }
                        dp[length][flag][check1][check2]+=count(length+1,1,i,check1);
                    }
            }
        return dp[length][flag][check1][check2];
    }
ll solve(ll a) {
    ll gt=0;
    chuyen(a);
    // int dai=s;
    // for(s=1;s<dai;s+=2)
    //     {
    //         for(int j=1;j<=s;j++)
    //             {
    //                 d[j]=9;
    //             }
    //         memset(dp,-1,sizeof(dp));
    //         gt+=count(1,0,0,0);
    //     }
    // chuyen(a);
    memset(dp,-1,sizeof(dp));
    // cout<<s<<endl;
    // for(int i=1;i<=s;i++)cout<<d[i]<<" ";
    gt+=count(1,0,0,0);
    return gt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("PFnum.inp","r",stdin);
    freopen("PFnum.out","w",stdout);
    cin>>a>>b;
    cout<<solve(b)-solve(a-1);
}
*/

/*
dinhnhoquan
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

string a, b;
const int N = 1005;
ll dp[N][60][2][2][2];


ll Backtracking(int i, char cp = '/', char c = '/', bool touch_a = false, bool bA = false, bool sB = false) {
	if(i == (int)b.size()) return 1;
	if(dp[i][(int)c][touch_a][bA][sB] != -1) return dp[i][(int)c][touch_a][bA][sB];
	dp[i][(int)c][touch_a][bA][sB] = 0;
	char tmp;
	for(char x = '0'; x <= '9'; x++) {
		if(x != c && x != cp && (bA || x >= a[i]) && (sB || x <= b[i])) {
			if(!touch_a && x == '0') tmp = '/';
			else tmp = x;
			dp[i][(int)c][touch_a][bA][sB] += Backtracking(i + 1, c, tmp, touch_a || x > '0', bA || (x > a[i] && (touch_a || x > '0')), sB || x < b[i]);
		}
	}
	return dp[i][(int)c][touch_a][bA][sB];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	read_file("PFNum");
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	while(a.size() < b.size()) a = '/' + a;
	cout << Backtracking(0) << "\n";
	return 0;
}
*/