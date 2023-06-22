#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 3;
const long long maxN = 2e9 + 2;
int cnt[N + 2];
long ans = 0;
int parent[N + 2];
int sz[N + 2];
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v) {
    if(v == parent[v])
        return v;
    return find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int a[N + 2];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(cnt[a[i]] == 1) {
            cout << ans << " ";
            continue;
        }
        cnt[a[i]]++;
        make_set(a[i]);
        if(cnt[a[i] - 1] == 1 && cnt[a[i] + 1] == 1) {
            int u = sz[find_set(a[i] - 1)];
            if(u % 2 != 0)
                u++;
            u /= 2;
            int v = sz[find_set(a[i] + 1)];
            if(v % 2 != 0)
                v++;
            v /= 2;
            union_sets(a[i] - 1, a[i]);
            union_sets(a[i] + 1, a[i]);
            int c = sz[find_set(a[i])];
            if(c % 2 != 0)
                c++;
            c /= 2;
            ans = ans + c - u - v;
        } else if(cnt[a[i] - 1] == 1) {
            int u = sz[find_set(a[i] - 1)];
            if(u % 2 != 0)
                u++;
            u /= 2;
            union_sets(a[i] - 1, a[i]);
            int c = sz[find_set(a[i])];
            if(c % 2 != 0)
                c++;
            c /= 2;
            ans = ans + c - u;
        } else if(cnt[a[i] + 1] == 1) {
            int v = sz[find_set(a[i] + 1)];
            if(v % 2 != 0)
                v++;
            v /= 2;
            union_sets(a[i] + 1, a[i]);
            int c = sz[find_set(a[i])];
            if(c % 2 != 0)
                c++;
            c /= 2;
            ans = ans + c - v;
        } else {
            ans += 1;
        }
        cout << ans << " ";
    }
    return 0;
}
