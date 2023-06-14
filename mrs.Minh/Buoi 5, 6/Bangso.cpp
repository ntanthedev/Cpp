#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, s[N], flag, dem = 0;
ll vt[N];
void output(){
    for(int i = 1; i <= flag; i++){
        if(vt[i] == 1)
            cout<<"O";
        else
            cout<<"T";
    }
    cout<<'\n';
    dem++;
}
void tim(int i){
    for(int j = 1; j <= 2; j++){
        vt[i] = j;
        s[i] = s[i-1] + j;
        if(s[i] == n){
            flag = i;
            output();
        }
        else
            if(s[i] < n)
                tim(i+1);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bangso.inp","r",stdin);
    freopen("Bangso.out","w",stdout);
    cin>>n;
    //vt.reserve(n);
    s[0] = 1;
    tim(1);
    cout<<dem;
}