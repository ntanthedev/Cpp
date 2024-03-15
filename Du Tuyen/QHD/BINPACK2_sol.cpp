#include <bits/stdc++.h>
using namespace std;

int test,n,k,i;
int t[100100];
long long s,sum;
pair <int,int> a[100100];

int main() {
    freopen("binpack2.inp","r",stdin);
    freopen("binpack2.out","w",stdout);

    scanf("%d",&test);
    while (test--) {
        scanf("%d %d",&n,&k);
        sum=0;
        for (i=1;i<=n;i++) {
            scanf("%d",&a[i].first);
            a[i].second=i;
            sum+=a[i].first;
        }
        sort(a+1,a+1+n);
        for (i=n-k+1;i<=n;i++) t[a[i].second]=0;
        sum=sum/2;
        s=0;
        for (i=n-k;i>=1;i--)
            if (s+a[i].first<=sum) {
                t[a[i].second]=1;
                s+=a[i].first;
            }
            else t[a[i].second]=2;
        for (i=1;i<=n;i++)
            printf("%d",t[i]);
        printf("\n");
    }
}