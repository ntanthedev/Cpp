#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e3+9;
ll L[N][N];
ll n, m, a[N], b[N];
void tim(){
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
}
void solve(){
    tim();
    stack<int>st;
    ll res = L[m][n];
    cout<<res<<'\n';
    ll i = m, j = n; 
    while((i > 0)&&(j > 0)){
        if(a[i] == b[j]){
            st.push(a[i]);
            i--;
            j--;
            res--;
        }
        else
            if(L[i][j] == L[i-1][j])
                i--;
            else
                j--;
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("daycon.inp","r",stdin);
    //freopen("daycon.out","w",stdout);
    cin>>m>>n;
    memset(L, 0, sizeof(L));
    for(int i = 1; i <= m; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++)
        cin>>b[i];
    solve();
}