#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e3+9;
ll a[N][N], m, n, h[N];
stack<ll>l, r;
ll trai[N], phai[N], x, gmax = LLONG_MIN;

/// Tim left
void findleft(){
    while(!l.empty() && h[l.top()] >= h[x])
        l.pop();
    if(l.empty())
        trai[x] = 0;
    else
        trai[x] = l.top();
    l.push(x);
}
/// Tim right
void findright(){
    while(!r.empty() && h[r.top()] >= h[x])
        r.pop();
    if(r.empty())
        phai[x] = n+1;
    else
        phai[x] = r.top();
    r.push(x);
}
// Xu ly
void slove(){
    for(x = 1; x <= n; x++)
        findleft();
    for(x = n; x >= 1; x--)
        findright();
    ll res;
    for(int j = 1; j <= n; j++){
        res = (phai[j] - trai[j] - 1) * h[j];
        if(res > gmax){
            gmax = res;
        }
    }
    cout<<gmax;
}
// Ham main
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("MAXRECT.inp","r",stdin);
    freopen("MAXRECT.out","w",stdout);
    cin>>m>>n;
    char ch;
    for(int j = 1; j <= n; j++)
        h[j] = 0;
    for(int i = 1; i <= m; i++){        
        for(int j = 1; j <= n; j++){
            cin>>ch;
            if(ch == 'B'){
               a[i][j] = 1;
               h[j] = 0;
            }
            if(ch == 'W'){
                a[i][j] = 0;
                h[j]++;
            }
        }
        slove();    
    } 
}