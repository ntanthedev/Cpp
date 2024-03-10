#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define taskname "MAXRECT"
const int maxN = 1002;
int m, n, h[maxN], L[maxN], res = 0;
vector<int> Stack; //Using vector to reset efficiently



inline void Update(int Area)
{
    if (Area > res) res = Area;
}

void ReadALine()
{
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'B') h[i] = 0;
        else h[i]++;
    }
}
void Init()
{
    fill_n(h, maxN, 0);
    h[0] = h[n + 1] = -1;
    Stack.reserve(maxN);
}
void FindRect()
{
    Stack.resize(0);
    Stack.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (h[Stack.back()] >= h[i]) Stack.pop_back();
        L[i] = Stack.back();
        Stack.push_back(i);
    }
    Stack.resize(0);
    Stack.push_back(n + 1);
    for (int i = n; i >= 1; i--)
    {
        while (h[Stack.back()] >= h[i]) Stack.pop_back();
        int R = Stack.back();
        Update((R - L[i] - 1) * h[i]);
        Stack.push_back(i);
    }
}
void Solve()
{
    for (int i = 1; i <= m; i++)
    {
        ReadALine();
        FindRect();
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> m >> n;
    Init();
    Solve();
}
