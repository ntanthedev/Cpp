#include<bits/stdc++.h>
#define tag "SPEC"
#define ll long long 
const long long N = 1e6+9;
using namespace std;
ll n, a[N];
void sub1(){
    ll gmax = 0;
    for(int i = 1; i <= n; i++){
        ll res = 0;
        if(a[i] != 0) res = 1;
        for(int j = i+1; j <= n+1; j++){
            if(a[j]*a[j-1] > 0)
                res++;
            else
                break;
        }
        gmax = max(gmax, res);
    }
    cout << gmax;
}
void sub2(){
    ll d = 0, gmax = 0;
    if(a[1]!=0) d = 1, gmax = 1;
    for(int i = 2; i <= n;i++){
        if((a[i]*a[i-1]) <= 0)
            d = 1;
        else
            d++;
    gmax = max(gmax, d);
        //cout << d << " " ;
    }
    cout << gmax;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n <= 1e3)
        sub2();
    else
        sub2();
}