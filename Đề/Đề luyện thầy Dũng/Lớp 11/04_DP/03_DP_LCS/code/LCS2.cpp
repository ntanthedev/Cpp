#include <iostream>
#include <cstdio>
#include <string>
#include <array>
using namespace std;
const int maxM = 1e3;
const int maxN = 1e6;
const int maxABC = 26;
const int infty = maxN + 1;
int m, n, x[maxM + 1], y[maxN + 1];
typedef array<int, maxABC> TPos;
TPos g[maxN + 1];
int f[maxM + 1][maxM + 1];

void Enter()
{
    string s;
    getline(cin, s);
    m = s.length();
    for (int i = 1; i <= m; i++)
        x[i] = s[i - 1] - 'A';
    getline(cin, s);
    n = s.length();
    for (int i = 1; i <= n; i++)
        y[i] = s[i - 1] - 'A';
}

void Init()
{
    fill(g[n].begin(), g[n].end(), infty);
    for (int i = n - 1; i >= 0; i--)
    {
        g[i] = g[i + 1];
        g[i][y[i + 1]] = i + 1;
    }
}

inline void Minimize(int& Target, int Value)
{
    if (Value < Target) Target = Value;
}

void Solve()
{
    for (int i = 0; i <= m; i++)
        f[i][0] = 0;
    for (int j = 1; j <= m; j++)
        f[0][j] = infty;
    for (int i = 1; i <= m; i++)
        for (int k = 1; k <= m; k++)
        {
            f[i][k] = f[i - 1][k];
            if (f[i - 1][k - 1] != infty)
                Minimize(f[i][k], g[f[i - 1][k - 1]][x[i]]);
        }
}

void Print()
{
    int k = m;
    while (f[m][k] == infty) k--;
    string s;
    s.resize(k);
    for (int i = m; i > 0; i--)
        if (f[i][k] != f[i - 1][k])
            s[--k] = x[i] + 'A';
    cout << s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("LCS2.inp", "r", stdin);
    freopen("LCS2out", "w", stdout);

    Enter();
    Init();
    Solve();
    Print();
}
