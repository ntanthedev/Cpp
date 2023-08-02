#include<bits/stdc++.h>
#define tag "BNUM"
#define ll long long 
const long long N = 1e6+9;
using namespace std;
ll n, s = 0;
bool is_prime(int x)
{
    if(x < 2)
        return 0;
    for(int i = 2 ; i <= sqrt(x) ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
void solve(){
    while(n > 0){
        s += (n%10)*(n%10);
        n /= 10;
    }
    if(is_prime(s))
        cout << 1 << '\n';
    else
        cout << -1 << '\n';
    cout << s;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n;
    solve();
}