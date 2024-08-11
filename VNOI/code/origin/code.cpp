#include<bits/stdc++.h>
using namespace std;
#define se second
#define fi first
#define int long long

const int Nmax = 1e6 + 5;
const int LogN = 17;
const int N = 1e6 + 207;
const int MOD = 1e18 + 3;

int n , k , h , q;
int a[Nmax];
vector <int> idx[Nmax];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	#define task "code"
	if(fopen(task ".inp", "r")) {
		freopen(task ".inp", "r", stdin);
		freopen(task ".out", "w", stdout);
	}

    cin >> n >> q;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }

    while(q--)
    {
        int l , r , k;
        cin >> l >> r >> k;
        int L = lower_bound(idx[k].begin() , idx[k].end() , l) - idx[k].begin();
        int R = upper_bound(idx[k].begin() , idx[k].end() , r) - idx[k].begin();
        cout << R - L << '\n';
    }
}