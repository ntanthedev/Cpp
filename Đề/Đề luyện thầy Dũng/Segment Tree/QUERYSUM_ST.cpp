#define taskname "QUERYSUM"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxN = 1e5 + 1;
int n, m, salary[maxN];
struct TSegmentTree
{
    int L[4 * maxN], H[4 * maxN];
    lli sum[4 * maxN];
    int leaf[maxN];
    void Build(int x, int low, int high)
    {
        L[x] = low; H[x] = high;
        sum[x] = 0;
        if (low == high)
            leaf[low] = x;
        else
        {
            int middle = (low + high) / 2;
            Build(x << 1, low, middle);
            Build((x << 1) + 1, middle + 1, high);
        }
    }
    void Update(int k, int w)
    {
        int delta = w - salary[k];
        int x = leaf[k];
        for (; x > 0; x >>= 1)
            sum[x] += delta;
        salary[k] = w;
    }
    int qi, qj;
    lli Request(int x)
    {
        if (L[x] > qj || H[x] < qi) return 0;
        if (qi <= L[x] && H[x] <= qj) return sum[x];
        return Request(x << 1) + Request((x << 1) + 1);
    }
    lli Query(int i, int j)
    {
        qi = i; qj = j;
        return Request(1);
    }
} tree;

void Enter()
{
    cin >> n >> m;
    fill_n(salary + 1, n, 0);
    tree.Build(1, 1, n);
}

void Solve()
{
    for (; m > 0; --m)
    {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if (c == 'S') tree.Update(i, j);
        else cout << tree.Query(i, j) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve();
}
