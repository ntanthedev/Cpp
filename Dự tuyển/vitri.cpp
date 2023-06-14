#include<bits/stdc++.h>
#define ll long long
#define xau "vitri"
const int N = 1e6+9;
using namespace std;
ll n, a[N], s[2*N], smin[2*N], ans = 0;
deque<int> dq;
///----------------------------------fast read
ll read(){
    bool neg = false;
    char c = getchar();
    for(; c < '0' || '9' < c; c = getchar())
        if(c == '-') neg = !neg;
    ll k = 0;
    while('0' <= c && c <= '9')
        k = (k << 3) + (k << 1) + c - '0', c = getchar();
    return neg ? -k : k;
}
///---------------------------Sub1
void sub1(){
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = i; j < n+i; j++){
            if(s[j] - s[i-1] <= 0){
                flag = false;
                break;
            }
        }
        if(flag)
            ans++;
    }
    //for(int i = 1; i <= 2*n; i++)
        //cout<<s[i]<<" ";
    cout<<ans;
}
///------------------ Sub2
void sub2(){
    for(int i = 2*n; i >= 1; i--){
        while(!dq.empty() && s[dq.back()] >= s[i])
            dq.pop_back();
        dq.push_back(i);
        if(dq.front() + n <= i)
            dq.pop_front();
        //if(i >= n)
            smin[i] = s[dq.front()];
    }
    //for(int i = 1; i <= 2*n; i++)
        //cout<<smin[i]<<" ";
    for(int i = n; i >= 1; i--){
        if(smin[i] - s[i-1] > 0)
            ans++;
    }
    cout<<ans;
}
///--------------------------
void solve(){
    if(n <= 5*1e3)
        sub1();
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
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    n = read(); s[0] = 0;
    for(int i = 1; i <= n; i++){
        a[i] = read();
        s[i] = s[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++)
        s[n+i] = s[i] + s[n];
    solve();
}

