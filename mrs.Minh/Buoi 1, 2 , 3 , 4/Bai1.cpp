#include<bits/stdc++.h>
long long n, k, a[1000009], dem = 0;
bool s[10000009];
using namespace std;
void snt(){
    memset(s,true,sizeof(s));
    s[0] = false;
    s[1] = false;
    for(int i = 2; i <= 1e4; i++){
        if(s[i]){
            for(int j = i*i; j <= 1e4; j+=i)
                s[j] = false;
        }
    }
}
bool slove(long long x){
    if(x<k && s[x] == true)
        return true;
    return false;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
    cin>>n>>k;
    snt();
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(slove(a[i])){
            dem++;
        }
    }
    cout<<dem;
}
