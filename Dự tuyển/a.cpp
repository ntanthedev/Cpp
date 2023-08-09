#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

void build(int x, int l, int r, vector<pair<int, int>> &a, vector<int> tree[]) {
    if(l == r) {
        tree[x].push_back(a[l].second);
        return;
    }
    int mid = (l+r)/2;
    build(x*2, l, mid, a, tree);
    build(x*2+1, mid+1, r, a, tree);
    merge(tree[2*x].begin(), tree[2*x].end(), tree[2*x+1].begin(), tree[2*x+1].end(), back_inserter(tree[x]));
}

int QRec(int st, int ed, int qst, int qed, int x, int K, vector<int> tree[]) {
    if(st == ed) {
        return tree[x][0];
    }
    int mid = (st + ed)/2;
    int last = (upper_bound(tree[2*x].begin(), tree[2*x].end(), qed) - tree[2*x].begin());
    int first = (lower_bound(tree[2*x].begin(), tree[2*x].end(), qst) - tree[2*x].begin());
    int M = last - first;
    if(M >= K) 
        return QRec(st, mid, qst, qed, 2*x, K, tree);
    else 
        return QRec(mid+1, ed, qst, qed, 2*x+1, K - M, tree);
}

int Query(int qst, int qed, int K, int n, vector<pair<int, int>> &a, vector<int> tree[]) {
    return QRec(0, n-1, qst-1, qed-1, 1, K, tree);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("DQUERY.inp","r")){
        freopen("DQUERY.inp","r",stdin);
        freopen("DQUERY.out","w",stdout);
    }
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    fo(i, 0, n-1)
        cin >> a[i];
    vector<pair<int, int>> v;
    fo(i, 0, n-1)
        v.push_back(make_pair(a[i], i));
    sort(v.begin(), v.end());
    vector<int> tree[N];
    build(1, 0, n-1, v, tree);
    while(m--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << a[Query(l, r, k, n, v, tree)] << '\n';
    }
}