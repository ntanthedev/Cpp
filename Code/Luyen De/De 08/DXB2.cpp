#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, gmax = LLONG_MIN, flag = 0, vt = -1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DXB2.inp","r",stdin);
    freopen("DXB2.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] > gmax && a[i] < 0){
            gmax = a[i];
            vt = i;
        }
    }
    cout<<vt;
}
