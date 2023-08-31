#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define left (id<<1)
#define right (id<<1)+1
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const int N = 1e5+10;
const ll MOD = 1e9+7;

int n, a[N], lmax[4*N], lmin[4*N];

void build(int id, int l, int r) {
    if(l == r) {
        lmax[id] = a[l];
        lmin[id] = a[l];
    }
    else {
        int mid = (l+r)/2;
        build(left, l, mid);
        build(right, mid+1, r);
        lmax[id] = max(lmax[left], lmax[right]);
        lmin[id] = min(lmin[left], lmin[right]);
    }
}

int get_max(int x, int l, int r, int d, int c) {
    if(l > c || r < d)
        return INT_MIN;
    if(d <= l && r <= c)
        return lmax[x];
    int mid = ((l+r)>>1);
    return max(get_max(x<<1, l, mid, d, c), get_max((x<<1)+1, mid+1, r, d, c));
}

int get_min(int x, int l, int r, int d, int c) {
    if(l > c || r < d)
        return INT_MAX;
    if(d <= l && r <= c)
        return lmin[x];
    int mid = ((l+r)>>1);
    return min(get_min(x<<1, l, mid, d, c), get_min((x<<1)+1, mid+1, r, d, c));
}

void sub1() {
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = j+1; k <= n; k++) {
                for(int t = k; t <= n; t++) {
                    int t1 = get_max(1, 1, n, i, j), t2 = get_min(1, 1, n, k, t);
                    ans = (ans%MOD + (t1%MOD * t2%MOD)%MOD)%MOD;
                }
            }
        }
    }    
    cout << ans;
}

void sub2() {
    vi st;
    vi Lmax(n+2), Lmin(n+2), Rmax(n+2, 0), Rmin(n+2, 0);
    vll s(n+2);
    s[0] = 0;
    for(int i = 1; i <= n; i++)
        s[i] = s[i-1] + a[i];
    for(int i = 1; i <= n; i++) {
        while(!st.empty() && a[st.back()] < a[i]) {
            st.pop_back();
            if(a[st.back()] == a[i])
                Rmax[st.back()] = st.back()+1;
        }
        if(st.empty())
            Lmax[i] = 0; 
        else 
            Lmax[i] = st.back();
    }
    st.clear();
    for(int i = 1; i <= n; i++) {
        while(!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
            if(a[st.back()] == a[i])
                Rmin[st.back()] = st.back()+1;
        }
        if(st.empty())
            Lmin[i] = 0; 
        else 
            Lmin[i] = st.back();
    }
    st.clear();
    for(int i = n; i >= 1; i--) {
        if(Rmax[i] != 0)
            continue;
        while(!st.empty() && a[st.back()] < a[i]) 
            st.pop_back();
        if(st.empty())
            Rmax[i] = n+1; 
        else 
            Rmax[i] = st.back();
    }
    st.clear();
    for(int i = n; i >= 1; i--) {
        if(Rmin[i] != 0)
            continue;
        while(!st.empty() && a[st.back()] > a[i]) 
            st.pop_back();
        if(st.empty())
            Rmin[i] = n+1; 
        else 
            Rmin[i] = st.back();
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
                        
        } 
    }   
}

void sub3() {

}

void solve() {
    if(n <= 20) {
        build(1, 1, n);
        sub1();
    }
    else if(n <= 5000)
        sub2();
    else 
        sub3();
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

#define task "SUMWIX"
int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}