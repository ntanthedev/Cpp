#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;

ll test_case,n,b;
vector<ll>a[200009];
struct pt{
    ll g,x,vt;
};
vector<pt> q;
void solve(ll x) {
    ll g=0,vt=0;
    cin >> n;
    fr(i,1,n){
        ll t;
        cin>>t;
        a[x].push_back(t);
        if(g<t){
            vt=i;
            g=t;
        }
    }
    q.push_back({g,x,vt});
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> test_case;
    fr(i,1,test_case){
        solve(i);
    }
    vector<ll>kq;
    sort(q.begin(),q.end(),[](pt & x, pt & y){
        return (x.g<y.g||x.g==y.g&&x.vt>y.vt);
    });
    for(auto [x,y,z]: q){
        for(ll i: a[y]){
            kq.push_back(i);
        }
    }
    //for(ll j:kq) cout<<j<<" "; cout<<'\n';
    ll g=0,d=0;
    for(ll j: kq){
        if(j>g){
            d++;
        }
        g=max(g,j);
    }
    cout<<d;
}