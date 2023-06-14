#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1000009], b[1000009], x = 0, l;
map<long long, long long>A;
map<long long, long long>B;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DNUM6.inp","r",stdin);
    freopen("DNUM6.out","w",stdout);
    cin>>m>>n;;
    for(int i = 1; i <= m; i++){
        cin>>a[i];
        A[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        B[b[i]]++;
    }
    sort(a+1,a+1+m);
    l = max(m, n);
    long long t, k;
    for(int i = 1; i <= l; i++)
    {
        if(a[i] != a[i+1]){
            t = A[a[i]];
            k = B[a[i]];
            x += min(t, k);
        }
    }
    cout<<x;
}
