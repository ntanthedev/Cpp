#include<bits/stdc++.h>
#define tag "PPOINT"
#define ll long long 
const long long N = 1e6+9;
using namespace std;
ll n, gmin = 1e10, M[4];
struct pt{
    ll x, m;
};
pt a[N];
bool cmp(pt x, pt y){
    return x.x < y.x;
}
void sub1(){
    sort(a+1, a+1+n, cmp);
    ll d;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            memset(M, 0, sizeof(M));
            d = 0;
            for(int k = i; k <= j; k++){
                if(M[a[k].m] == 0)
                    d++;    
                M[a[k].m]++;
            }
            if(d == 3)
                gmin = min(a[j].x - a[i].x, gmin);
        }
    }
    if(gmin != 1e10)
        cout << gmin;
    else 
        cout << -1;
}
void sub2(){
    ll d = 0;
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i < n; i++){
        memset(M, 0, sizeof(M));
        M[a[i].m] = 1; d = 1;
        for(int j = i+1; j <= n; j++){
            if(!M[a[j].m]) d++; //if(M[a[j].m] == 0)
            M[a[j].m]++;
            if(d == 3){
                gmin = min(gmin, a[j].x - a[i].x);
                break;
            }
        }
    }    
    if(gmin == 1e10)
        cout << -1;
    else
        cout << gmin;
}
void sub3(){
    sort(a+1, a+1+n, cmp);
    ll i = 1, j = 2, d = 1;
    M[a[1].m]++;
    while(j <= n){
        if(!M[a[j].m])
            d++;
        M[a[j].m]++;
        while(d == 3){
            gmin = min(gmin, a[j].x - a[i].x);
            M[a[i].m]--;
            if(!M[a[i].m])
                d--;
            i++;
        }
        j++;
    }
    cout << (gmin != 1e10 ? gmin : -1);
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);    
    //freopen(tag".inp","r",stdin);
    //freopen(tag".out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].m;
    if(n <= 1e2)
        sub1();
    else if(n <= 1e3)
        sub2();
    else 
        sub3();
}
