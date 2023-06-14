#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, b, k, q, s[N], sumarray = 0;
void subloi(){
    for(int m = 1; m <= q; m++){
        cin>>k>>b; k--; b = b%n; if(b == 0) b = n;
        ll ans, sum1, sum2, sl;
        if(b+k > n){
            sl = (b+k)/n;
            sum1 = s[n] - s[b-1];
            sum2 = s[(b+k) - (n*sl)];
            ans = sum1 + sum2 + (sl-1)*sumarray;
        }
        else{
            ans = s[b+k] - s[b-1];
        }
        cout<<ans<<'\n';
        //cout<<s[n]<<" "<<s[n] - s[b-1]<<" "<<sumarray<<" "<<b<<'\n';
    }
    //cout<<s[n]<<" "<<s[n-1]<<" "<<sumarray;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai2_10_2021_2022.inp","r",stdin);
    freopen("Bai2_10_2021_2022.out","w",stdout);
    cin>>n>>q; s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sumarray += a[i];
        s[i] = s[i-1] + a[i];
    }
    subloi();
}
/*
void subloi(){
    while(q--){
        cin>>k>>b; k--; b = b%n; if(b == 0) b = n;
        ll ans, sum1, sum2, sl;
        if(b+k > n){
            sl = (b+k)/n;
            sum1 = s[n] - s[b-1];
            sum2 = s[(b+k) - (n*sl)];
            ans = sum1 + sum2 + (sl-1)*sumarray;
        }
        else{
            ans = s[b+k] - s[b-1];
        }
        cout<<ans<<'\n';
        //cout<<s[
        loluyn]<<" "<<s[n] - s[b-1]<<" "<<sumarray<<" "<<b<<'\n';
    }
    //cout<<s[n]<<" "<<s[n-1]<<" "<<sumarray;
}
*/