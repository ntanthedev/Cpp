#include<bits/stdc++.h>
using namespace std;
long long s[10000009], a[10000009],n,gmax = LLONG_MIN,ld,lc,maxx = LLONG_MIN,ld2,lc2,check;
int main(){
    freopen("SPSUM5.inp","r",stdin);
    freopen("SPSUM5.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
        if(s[i]>=maxx||s[i]>0){
            maxx = s[i];
            lc2 = i;
        }
        if(a[i]>0){
            check++;
        }
    }
    if(check==0){
        cout<<0;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if((maxx - s[i-1]) > 0 && lc2-ld2+1>maxx){
            maxx = lc2-ld2+1;
            ld2 = i;
        }
    }
    if(ld2 == 0)
        ld2 = 1;
    cout<<ld2<<" "<<lc2;
}
