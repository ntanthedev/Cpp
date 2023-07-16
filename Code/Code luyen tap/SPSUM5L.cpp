#include <bits/stdc++.h>
using namespace std;
#define fast; ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lb long double
#define ll long long
#define MAX INT_MAX
#define MIN INT_MIN
#define MAXLL LLONG_MAX
#define el "\n"
#define fi first
#define se second
#define inp; freopen("xau.inp","r",stdin);
#define out; freopen("xau.out","w",stdout);
const long long N=1e6+9,M=1e9+7,D=5e4+1;
int f[N],a[N],p[N];
void solve(int n)
{
    int cnt=0;
	f[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		f[i] = min(f[i + 1], a[i]);
	}
	for (int i = 0; i < n; i++) {
		int l = i + 1, h = n - 1, ans = -1;
		while (l <= h) {
			int m = (l + h) / 2;
			if (f[m] < a[i]) {
                    ans = m;
				l = m + 1;
			}
			else
				h = m - 1;
		}
		++cnt,p[cnt]=ans;
	}
}
void rev(int n){
    int l=0,r=n-1;
    while (l<=r){
        swap(a[l],a[r]);
        ++l,--r;
    }
}
int main()
{
  	fast;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        a[i]=a[i-1]+x;
    }
    rev(n);
    solve(n+1);
    int x,y,mx=MIN;
    for (int i=1;i<=n;i++){
        //if (p[i]-i>mx)
           x=i,y=p[i],mx=p[i]-i;
cout << x << " " << y <<el;
    }

	return 0;
}
