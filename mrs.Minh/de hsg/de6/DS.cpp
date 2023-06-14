#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, s[N], dem = 0;
void slove(){
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if((s[j] - s[i-1])%n == 0)
                dem++;
        }
    }
    if(s[1]%n == 0)
        dem++;
    cout<<dem;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DS.inp","r",stdin);
    freopen("DS.out","w",stdout);
    s[0] = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
    }
    slove();
}