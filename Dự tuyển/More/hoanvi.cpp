#include<bits/stdc++.h>
#define tag "hoanvi"
#define ll long long 
const int N = 1e3+9;
using namespace std;
ll n, x[N];
map<ll, bool>M;
void cutdidm(){

}
void solve(int i){
    for(int j = 1; j <= n; j++){
        if(!M[j])
            x[i] = j;
        else
            j++;
        if(i == n)
            cutdidm();
        else
            solve(i+1);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n;
    solve(1);
}