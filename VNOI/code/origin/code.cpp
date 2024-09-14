#include<bits/stdc++.h>
    using namespace std;
    #define task "code"
    #define ii pair<int,int>
    #define fi first
    #define se second
    #define int long long
    #define mp make_pair
    #define lg2 20
    #define iii pair<int,ii>
    #define iiii pair<ii,ii>
    #define fii fi.fi
    #define fis fi.se
    #define sfi se.fi
    #define see se.se
    int dx[]={0LL,0LL,1,-1,1,1,-1,-1};
    int dy[]={1,-1,0LL,0LL,1,-1,1,-1};
    const int maxn=1e6+5;
    const int mod=1e9+7;
    int n,a[maxn],uoc[maxn],cur[maxn],kq[maxn];
    void sub1()
    {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans=0;
        for(int i = 1; i <= n; i++) {
            int dem_uoc = 0;
            for(int j = 1; j <= a[i]; j++) {
                if(a[i] % j == 0){
                    dem_uoc++;
                }
            }
            ans = max(ans, dem_uoc);
        }
        cout << ans;
    }
    void sub2(){
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans=0;
        for(int i = 1; i <= n; i++) {
            int tong_uoc= 0;
            for(int j = 1; j <= sqrt(a[i]); j++) {
                if(a[i] % j == 0){
                    tong_uoc++;
                    if(j != a[i] / j)
                        tong_uoc++;
                }
            }
            ans = max(ans, tong_uoc);
        }
        cout << ans;
    }
    void sub3()
    {
        for(int i = 1; i <= 1000000; i++){
            for(int j = i; j <= 1000000; j += i){
                uoc[j]++;
            }
        }
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, uoc[a[i]]);
        }
        cout << ans;
    }
    void toiuu() {
        for(int i = 1; i <= 1000000; i++)
            uoc[i]++;
        for(int i = 1; i <= 1000000; i++) {
            if(uoc[i] == 1) {
                int k = i;
                for(int so_mu = 1; k <= 1000000; so_mu++) {
                    for(int j = k; j <= 1000000; j += k) {
                        cur[j]++;
                    }
                    k*=i;
                }
                for(int j = i; j <= 1000000; j += i) {
                    uoc[j] *=(cur[j] + 1);
                    cur[j] = 0;
                }
            }
        }
        int ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            ans=max(ans,uoc[a[i]]);
        }
        cout<<ans;
    }
    signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if (fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);}
        sub3();
    }
