#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, scm = LLONG_MAX - 1, flag = 0, gmax = LLONG_MAX, vt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DP06.inp","r",stdin);
    freopen("DP06.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] < gmax)
            gmax = a[i];
    }
    for(int i = 1; i <= n; i++){
        if(a[i] > gmax && a[i] < scm){
            scm = a[i];
            flag = 1;
        }
    }
    int d = 0;
    if(flag == 0)
        d = 0;
    else
        for(int i = 1; i <= n; i++)
            if(a[i] == scm)
                d++;
    cout<<d;
}
