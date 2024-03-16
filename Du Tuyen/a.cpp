#include<bits/stdc++.h>
using namespace std;
#define task "BALANSUB"
const int N = 1e6 + 9;
typedef long long ll;
ll n, a[N], ans = 1, pos = 1, gmax = LLONG_MIN;
int main(){
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(fopen(task ".inp", "r")){
            freopen(task ".inp", "r", stdin);
            freopen(task ".out", "w", stdout);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll l = 1, r = 1;
    while(r <= n){
        while(a[r] < (r - l + 1)) l++;
        gmax = max(gmax, r - l + 1);
        cout << l << " " << r << '\n';
        r++;
    }
    cout << gmax;
}