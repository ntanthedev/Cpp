#include <bits/stdc++.h>
using namespace std;
 
const int N=1e6+9;

#define ll long long
#define fo(i,a,b) for (int i=a; i<=b; i++)
 
multiset<long long>m;
multiset<long long>::iterator it;
set<long long>s;
vector<long long>v;
stack<long long>st;

ll n ,a[N];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("increasingSUB.inp","r",stdin);
    //freopen("increasingSUB.out","w",stdout);
    cin>>n;
    fo(i,1,n){
        cin>>a[i];
    }
    fo(i,1,n){
        m.insert(a[i]);
        it = m.lower_bound(a[i]);
        it++;
        if(it!=m.end()){
            m.erase(it);
        }
    }
    cout<<m.size()<<'\n';
    for(it = m.begin(); it != m.end(); it++)
        cout<<*it<<" ";
}

// #include<bits/stdc++.h>
// #define tag "LIQ"
// #define ll long long 
// const int N = 1e5+9;
// using namespace std;
// ll m = 1, b[N], n, a[N];
// void solve(){
//     b[1] = a[1];
//     for(int i = 2; i <= n; i++){
//         if(a[i] < b[1])
//             b[1] = a[i];
//         if(a[i] > b[m])
//             b[++m] = a[i];
//         else{
//             ll t = lower_bound(b+1, b+1+m, a[i]) - b;
//             b[t] = a[i];
//         }
//     }
//     cout<<m<<'\n';
//     for(int i = 1; i <= m; i++)
//         cout<<b[i]<<" ";
// }

// int main(){
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     if(fopen(tag".inp","r")){
//         freopen(tag".inp","r",stdin);
//         freopen(tag".out","w",stdout);
//     }
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//         cin >> a[i];
//     solve();
// }