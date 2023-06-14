#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long base = 190997, mod = 978846151;
long long note1[1000001];
long long note2[1000001];
long long bas[1000001];
long long lg[1000001];
char a[1000001];
void update(long long id, long long l, long long r, long long pos,
            long long val) {
    if(l > pos || pos > r)
        return;
    if(l == r) {
        note1[id] = val;
        note2[id] = val;
        return;
    } 
    long long mid = (l + r) / 2;
    update(id * 2, l, (l + r) / 2, pos, val);
    update(id * 2 + 1, (l + r) / 2 + 1, r, pos, val);
    note1[id] = (note1[id * 2] * bas[r - mid] + note1[id * 2 + 1]) % mod;
    note2[id] = (note2[id * 2] + note2[id * 2 + 1] * bas[mid - l + 1]) % mod;
}
long long query1(long long id, long long l, long long r, long long L,
                 long long R) {
    if(l > R || r < L)
        return 0;
    if(L <= l && r <= R) {
        return note1[id];
    }
    long long mid = (l + r) / 2;
    if(R <= mid) {
        return query1(id * 2, l, mid, L, R);
    }
    return (query1(id * 2, l, (l + r) / 2, L, R) * bas[min(r, R) - mid] +
            query1(id * 2 + 1, (l + r) / 2 + 1, r, L, R)) %
           mod;
}
long long query2(long long id, long long l, long long r, long long L,
                 long long R) {
    if(l > R || r < L)
        return 0;
    if(L <= l && r <= R) {
        return note2[id];
    }
    long long mid = (l + r) / 2;
    if(mid < L) {
        return query2(id * 2 + 1, mid + 1, r, L, R);
    }
    return (query2(id * 2, l, (l + r) / 2, L, R) +
            query2(id * 2 + 1, (l + r) / 2 + 1, r, L, R) *
                bas[mid + 1 - max(l, L)]) %
           mod;
}
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    bas[0] = 1;
    for(long long i = 1; i <= n; i++) {
        lg[i] = log2(i);
        cin >> a[i];
        update(1, 1, n, i, a[i] - 'a');
        bas[i] = (bas[i - 1] * base) % mod;
    }
    for(long long i = 1; i <= m; i++) {
        long long num, l, r;
        char c;
        cin >> num;
        if(num == 2) {
            cin >> l >> r;
            if(query1(1, 1, n, l, r) == query2(1, 1, n, l, r)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            cin >> l >> c;
            a[l] = c;
            update(1, 1, n, l, a[l] - 'a');
        }
    }
}