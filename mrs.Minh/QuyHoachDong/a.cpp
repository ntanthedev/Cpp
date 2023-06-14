#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a, b;
map<ll, ll>P;
ll minprime[N];
void sang(){
    for(int i = 2; i <= 1e3; i++){
        if(minprime[i] == 0)
            for(int j = i*i; j <= 1e7; j+=i){
                if(minprime[j] == 0)
                    minprime[j] = i;
            }
    }
    for(int i = 2; i <= 1e6; i++){
        if(minprime[i] == 0){
            minprime[i] = i;
        }
    }
}
void slove(){
    ll souoc = 1, tonguoc = 1;
    for(ll n = a; n <= b; n++){
        while(n != 1){
            P[minprime[n]]++;
            n /= minprime[n];
        }
        ll c, m, t;
        for(auto i : P){
            m = i.second;
            souoc *= m+1;
            c = i.first;
            t = pow(c, m+1);
            tonguoc *= (t - 1)/(c-1);
        }
    }
    cout<<souoc<<" "<<tonguoc<<'\n';
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    sang();
    ll T;    
    cin>>T;
    for(int i = 1; i <= T; i++){
        cin>>a>>b;
        slove();
    }
}