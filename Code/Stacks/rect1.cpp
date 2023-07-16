#include<bits/stdc++.h>
using namespace std;
#define taskname "RECT"
const int maxN = 5e5 + 1;
int m, n, h[maxN], L[maxN], R[maxN];
typedef long long lli;
stack<int> s;
lli res, lan = 1, v1, v2, v3, v4;

void Enter()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
}

inline void Update(lli t)
{
    if (res < t){ 
        res = t;
    }
}

void Analyze()
{
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && h[s.top()] >= h[i])
            s.pop();
        if (s.empty()) L[i] = 0;
        else L[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();//Xoa stack

    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && h[s.top()] >= h[i])
            s.pop();
        if (s.empty()) R[i] = n + 1;
        else R[i] = s.top();
        s.push(i);
        if((lli(R[i] - L[i] - 1) * h[i]) > res){
            res = lli(R[i] - L[i] - 1) * h[i];            
        if(lan == 1){
                v1 = 1;
                v3 = h[i];
            }
            else{
                v1 = m - h[i] + 1;
                v3 = m;
            }
            v2 = L[i] + 1;
            v4 = R[i] - 1;
        }
    }
}

void Solve()
{
    res = 0;
    Analyze();
    for (int i = 1; i <= n; i++)
        h[i] = m - h[i];
    lan = 2;
    Analyze();
    cout << res<<'\n';
    cout<<v1<<" "<<v2<<'\n'<<v3<<" "<<v4;
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