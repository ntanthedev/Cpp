#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, s, a[N];
ll dem = 0;
void solve(){
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i++){
        if(s >= a[i]){
            s += a[i];
            dem++;
        }
        else
            break;
    }
    cout<<dem;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>s;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solve();
}