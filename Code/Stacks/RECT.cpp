#include<bits/stdc++.h>
using namespace std;
#define taskname "RECT"
const int maxN = 5e6 + 1;
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
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long 
// const long long R = 1e9+7;
// const long long N = 1e6+9;
// stack<int>l, r;
// ll trai[N], a[N], phai[N], n, m, h[N];
// ll res, lan = 1;
// ll v1, v2, v3, v4;
// ll gmax = LLONG_MIN;

// void findleft(ll x){
//     while(!l.empty() && h[l.top()] >= h[x])
//         l.pop();
//     if(l.empty())
//         h[x] = 0;
//     else
//         trai[x] = l.top();
//     l.push(x);    
// }

// void findright(long long x){
//     while(!r.empty() && h[r.top()] >= h[x])
//         r.pop();
//     if(r.empty())
//         phai[x] = n+1;
//     else
//         phai[x] = r.top();
//     r.push(x);
// }
// void slove(){
//     for(ll i = 1; i <= n; i++)
//         findleft(i);
//     for(ll i = n; i >= 1; --i)
//         findright(i);
//     for(int i = 1; i <= n; i++){
//         res = (phai[i] - trai[i] - 1) * h[i];
//         if(res > gmax){
//             gmax = res;
//             if(lan == 1){
//                 v1 = 1;
//                 v3 = h[i];
//             }
//             else{
//                 v1 = m - h[i] + 1;
//                 v3 = m;
//             }
//             v2 = trai[i] + 1;
//             v4 = phai[i] - 1;
//         }
//     }
// }

// int main()
// {
//     cin.tie(NULL); cout.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     freopen("RECT.inp","r",stdin);
//     freopen("RECT.out","w",stdout);
//     cin>>m>>n;
//     for(int i = 1; i <= n; i++){
//         cin>>h[i];
//     }
//     slove();
//     lan = 2;
//     while(!l.empty()) l.pop();
//     while(!r.empty()) r.pop();
//     for(int i = n; i >= 1; --i){
//         h[i] = m - h[i];
//     }
//     slove();
//     cout<<gmax<<'\n';
//     cout<<v1<<" "<<v2<<'\n'<<v3<<" "<<v4;
// }