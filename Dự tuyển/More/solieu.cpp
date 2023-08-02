#include<bits/stdc++.h>
#define tag "solieu"
#define ll long long 
const int N = 1e2+9;
using namespace std;
ll n, s, a[N], x[N], ans = 0;
void check(){
    int sum = 0;
    for(int j = 1; j <= n; j++){
        sum += x[j]*a[j];
    }
    if(sum == s)
        ans++;
}
void find(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n)
            check();
        else
            find(i+1);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    find(1);
    cout<<ans;
}