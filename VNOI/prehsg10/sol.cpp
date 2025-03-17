#include <bits/stdc++.h>

#define ll long long
#define fr(i, d, c) for (ll i = d; i <= c; i++)
#define fl(i, d, c) for (ll i = d; i >= c; i--)

const int M = 1e6 + 9;
using namespace std;

ll n, m, k, a[M];

struct sub1
{
    sub1()
    {
        fr(i, 1, n)
        {
            ll t, x, l, r;
            cin >> t;
            if (t == 1)
            {
                cin >> x >> l >> r;
                fr(j, l, r) a[j] += x;
            }
            else
            {
                cin >> l >> r;
                ll ans = 0;
                fr(j, l, r)
                {
                    ans += (a[j] <= k);
                }
                cout << ans << '\n';
            }
        }
    }
};

struct sub2
{
    sub2()
    {
        bool pre = false;
        fr(i, 1, n)
        {
            ll t, x, l, r;
            cin >> t;
            if (t == 1)
            {
                cin >> x >> l >> r;
                a[l] += x;
                a[r + 1] -= x;
            }
            else
            {
                if (pre == false)
                {
                    fr(j, 1, m) a[j] += a[j - 1];
                    fr(j, 1, m) a[j] = a[j - 1] + (a[j] <= k);
                    pre = true;
                }
                cin >> l >> r;
                cout << a[r] - a[l - 1] << '\n';
            }
        }
    }
};

struct sub3
{
    sub3()
    {
        multiset<pair<ll, ll>> cur;
        ll sum = 0;
        fr(i, 1, n)
        {
            ll t, x, l, r;
            cin >> t;
            if (t == 1)
            {
                cin >> x >> l >> r;
                while (true)
                {
                    auto id = cur.lower_bound({l, 0});
                    if (id == cur.end())
                        break;

                    auto [f, s] = *id;
                    if (f <= r)
                    {
                        l = min(l, f);
                        r = max(r, s);
                        sum -= s - f + 1;
                        cur.erase(id);
                    }
                    else
                        break;
                }

                while (true)
                {
                    auto id = cur.lower_bound({l, 0});
                    if (id == cur.begin())
                        break;
                    id--;

                    auto [f, s] = *id;
                    if (l <= s)
                    {
                        l = min(l, f);
                        r = max(r, s);
                        sum -= s - f + 1;
                        cur.erase(id);
                    }
                    else
                        break;
                }

                sum += r - l + 1;
                cur.insert({l, r});
            }
            else
            {
                cin >> l >> r;
                cout << m - sum << '\n';
            }
        }
    }
};

struct sub4
{
    ll rig[M], sum = 0;
    bool dd[M];

    ll find(ll a)
    {
        if (rig[a] == a)
            return a;
        return rig[a] = find(rig[a]);
    }

    void uni(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (a > b)
                swap(a, b);
            rig[a] = b;
        }
    }

    sub4()
    {
        fr(i, 0, m + 1) rig[i] = i, dd[i] = false;
        fr(i, 1, n)
        {
            ll t, x, l, r;
            cin >> t;
            if (t == 1)
            {
                cin >> x >> l >> r;
                fr(i, l, r)
                {
                    i = find(i);
                    if (i > r)
                        break;

                    if (dd[i] == false)
                    {
                        dd[i] = true;
                        sum++;
                    }
                    if (dd[i + 1])
                    {
                        uni(i, i + 1);
                    }
                }
                if (dd[l - 1])
                    uni(l - 1, l);
            }
            else
            {
                cin >> l >> r;
                cout << m - sum << '\n';
            }
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    if (k != 0 && n <= 1e3 && m <= 1e3)
        delete new sub1;
    else if (k != 0 && n <= 1e6 && m <= 1e6)
        delete new sub2;
    else if (k == 0 && n <= 1e5 && m <= 1e5)
        delete new sub3;
    else if (k == 0 && n <= 1e6 && m <= 1e6)
        delete new sub4;
}