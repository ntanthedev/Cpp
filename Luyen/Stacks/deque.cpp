#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll m, n, a[N], x, ans;
multiset<ll>s;
multiset<ll>::iterator it;
void solve(){
    while(m--){
        cin >> x;
        it = s.upper_bound(x);
        if(it == s.begin())
            cout<<-1<<'\n';
        else{
            it--;
            cout<<*it<<'\n';
            s.erase(it);
        }
    }

}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> x;
        s.insert(x);
    }
    solve();
}
