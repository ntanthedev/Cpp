#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+9;
const int R = 1e9+7;
using namespace std;
ll n, a[N];
void slove(){
    sort(a+1, a+1+n);
    ll dem = 1, gmax = 0, c = a[n], res = a[n];
    for(int i = n-1; i >= 1; --i){
        if(c == 0)  break;
        c = min(a[i], c-1);
        dem++;
    }
    cout<<dem;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("HIGTIL.inp","r",stdin);
    freopen("HIGTIL.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    slove();
}

