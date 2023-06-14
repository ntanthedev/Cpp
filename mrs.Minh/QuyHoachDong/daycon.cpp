#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e3+2;
ll a[N], L[N], T[N], kq[N];
ll n, res, cs;
void input(){
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
}
void slove(){
    //memset(L, 1, sizeof(L));
    memset(T, 0, sizeof(T));
    for(int i = 1; i <= n; i++){
        L[i] = 1;
        for(int j = 1; j < i; j++){
            if((a[j]<=a[i]) && (L[i]<L[j]+1)){
                L[i] = L[j]+1;
                T[i] = j;
            }
        }
    }
}
void output(){
    res = 1, cs = 1;
    for(int i = 2; i <= n; i++){
        if(L[i] > res){
            res = L[i];
            cs = i;
        }
    } 
    cout<<res<<'\n';
    int j = res;
    do{
        kq[j] = a[cs];
        cs = T[cs];
        j--;
    }while(j != 0);
    for(int i = 1; i <= res; i++){
        cout<<kq[i]<<" ";
    }  
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("daycon.inp","r",stdin);
    freopen("daycon.out","w",stdout);
    input();
    slove();
    output();
}