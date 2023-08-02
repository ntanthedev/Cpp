#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define taskname "IS"

using namespace std;

typedef long long lli;

const int maxN = 1e5 + 1;
const int infty = 1e9 + 1;

int n, a[maxN], w[maxN], id[maxN];
lli bit[maxN], f[maxN];

void Enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
}

void Init()
{
    for (int i = 1; i <= n; ++i)
        id[i] = i;
    
    sort(id + 1, id + n + 1, [](int i, int j) {
        return a[i] < a[j];
    });
    
    int old = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[id[i]] != old)
            old = a[id[i]], ++cnt;
        a[id[i]] = cnt;
    }
    
    fill_n(bit + 1, n, 0);
}

void SetValue(int x, lli Val)
{
    for (; x <= n; x += x & -x)
    {
        if (bit[x] < Val)
            bit[x] = Val;
        else
            break;
    }
}

lli Query(int x)
{
    lli res = 0;
    for (; x > 0; x &= x - 1)
    {
        if (res < bit[x])
            res = bit[x];
    }
    return res;
}

void Solve()
{
    lli resf = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = Query(a[i] - 1) + w[i];
        if (f[i] > resf)
            resf = f[i];
        SetValue(a[i], f[i]);
    }
    
    vector<int> res;
    int resa = infty;
    for (int i = n; i > 0; --i)
    {
        if (a[i] < resa && f[i] == resf)
        {
            res.push_back(i);
            resa = a[i];
            resf = f[i] - w[i];
        }
    }
    
    cout << res.size() << '\n';
    for (auto it = res.rbegin(); it != res.rend(); ++it)
        cout << *it << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen(taskname".inp","r")){
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    Enter();
    Init();
    Solve();
    
    return 0;
}
