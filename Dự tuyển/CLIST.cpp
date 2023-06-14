#include<bits/stdc++.h>
#define ll long long
#define xau "CLIST"
const int N = 1e6+9;
using namespace std;
ll n, k, l, a[N], x;
deque<ll> dq;
//---------------------
void top(ll f){
    for(int i = 1; i <= n; i++)
        dq.push_back(a[i]);
    while(f--){
        ll t = dq.front();
        dq.push_back(t);
        dq.pop_front();
    }
    for(int i = 1; i <= n; i++){
        a[i] = dq.front();
        dq.pop_front();
    }
}
void bottom(ll f){
    for(int i = 1; i <= n; i++)
        dq.push_back(a[i]);
    while(f--){
        ll t = dq.back();
        dq.push_front(t);
        dq.pop_back();
    }
    for(int i = 1; i <= n; i++){
        a[i] = dq.front();
        dq.pop_front();
    }
}
//--------------------------
void sub1(){
    l = l%n;
    k = k%n;
    x = x%n;
    ll t;
    if(l > k)
        t = l-k;
    else
        t = k-l;
    if(k > l){
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= t; j++)
                top(1); //cout<<"lan "<<i<<": ";
//            for(int j = 1; j <= n; j++)
//                cout<<a[j]<<" ";
//            cout<<'\n';
        }
    }
    else{
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= t; j++)
                bottom(1); //cout<<"lan "<<i<<": ";
//            for(int j = 1; j <= n; j++)
//                cout<<a[j]<<" ";
//            cout<<'\n';
        }
    }
    for(int i = 1; i <= n; i++)
        cout<<a[i]<<" ";
}
//-----------------------------------------------
void sub2(){
    l = l%n;
    k = k%n;
    x = x%n;
    ll t;
    if(l > k)
        t = l-k;
    else
        t = k-l;
    if(k > l){
        for(int i = 1; i <= x; i++){
            top(t);
            //cout<<"lan "<<i<<": ";
//            for(int j = 1; j <= n; j++)
//                cout<<a[j]<<" ";
//            cout<<'\n';
        }
    }
    else{
        for(int i = 1; i <= x; i++){
            bottom(t); //cout<<"lan "<<i<<": ";
//            for(int j = 1; j <= n; j++)
//                cout<<a[j]<<" ";
//            cout<<'\n';
        }
    }
    for(int i = 1; i <= n; i++)
        cout<<a[i]<<" ";
}
void solve(){
    if(n <= 1e3)
        sub2();
    else
        sub2();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    cin >> n >> k >> l;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> x;
    solve();
}
