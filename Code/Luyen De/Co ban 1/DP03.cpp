#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, flag = 0, gmax = LLONG_MAX, vt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DP03.inp","r",stdin);
    freopen("DP03.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] < gmax && a[i] > 0 && a[i]%2 == 0){
            gmax = a[i];
            vt = i;
            flag = 1;
        }
    }
    if(flag == 0)
        cout<<-1;
    else
        cout<<vt;
}
