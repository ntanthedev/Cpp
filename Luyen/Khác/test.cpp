#include <bits/stdc++.h>

using namespace std;

long long n;
int cnt;

int main()
{
    //freopen("SOUOC.inp","r",stdin);
    //freopen("SOUOC.out","w",stdout);

    cin>>n;
    for (long long i=1;i*i<=n;i++)
        if (n%i==0)
        {
            if (i%2!=0)
                cnt++;
            if (n/i!=i and (n/i)%2!=0)
                cnt++;
        }
    cout<<cnt;

    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
const long long M = 1000009;
long long n, a[M], psum[M], pmin[M], pgmax[M],ssum[M],smin[M],sgmax[M];
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    psum[0] = 0; pmin[0] = LLONG_MAX; pgmax[0] = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        psum[i] = psum[i-1]+a[i];
        pmin[i] = min(psum[i], pmin[i-1]);
        pgmax[i] = max(psum[i]-pmin[i],pgmax[i-1]);
    }
    ssum[0] = 0; smin[0] = LLONG_MAX; sgmax[0] = LLONG_MIN;
    for(int i = 1; i <= n; i++)
    {
        ssum[i] = a[i] + ssum[i+1];
        smin[i] = min(ssum[i], smin[i+1]);
        sgmax[i] = max(ssum[i]- smin[i], sgmax[i+1]);
    }
    long long gmax = LLONG_MIN;
    for(int i = 1; i <= n; i++)
        gmax = max(gmax, pgmax[i] + sgmax[i]);
    cout<<gmax;
}*/
/*#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
*/
