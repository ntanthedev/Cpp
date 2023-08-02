#include<bits/stdc++.h>
#define tag "TKS"
#define ll long long 
const int N = 1e3+9;
using namespace std;
ll m, n, x, y;
bool visited[N], a[N][N]; 
void solve(){

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        visited[i] = true;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    solve();
}