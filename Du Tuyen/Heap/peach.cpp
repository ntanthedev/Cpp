#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
struct pt
{
    int t, k;
};
int n, a, b;
pt* Peach[N];
struct Less
{
    bool operator()(pt* x, pt* y)
    {
        return x->k < y->k;
    }
};
priority_queue<pt*, vector<pt*>, Less> pq;

void input()
{
    cin>>n>>a>>b;
    for (int i = 0; i < n; i++)
    {
        Peach[i] = new pt;
        cin>>Peach[i]->t>>Peach[i]->k;
    }
    sort(Peach, Peach + n, [](pt* x, pt* y)
         {
             return x->t < y->t;
         });
}

void solve()
{
    if (a < b - n) a = b - n;
    int p = 0;
    long long res = 0;
    for (int Time = a; Time < b; Time++)
    {
        while (p < n && Peach[p]->t <= Time)
            pq.push(Peach[p++]);
        if (!pq.empty())
        {
            res += pq.top()->k;
            pq.pop();
        }
    }
    for (int i = 0; i < n; i++)
        delete Peach[i];
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("peach.inp","r",stdin);
    freopen("peach.out","w",stdout);
    input();
    solve();
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double 
// const long long MOD = 1e9+7;
// const long long N = 1e6+9;
// ll n, a, b, la, lb;
// priority_queue<ll>q;
// struct pt{
//     ll t, k;
// };
// pt p[N];
// bool cmp(pt g, pt h){
//     return g.t < h.t;
// }
// void solve(){
//     sort(p+1, p+1+n, cmp);
//     for(int i = 1; i <= n; i++){
//         if(p[i].t >= a){
//             la = i;
//             break;
//         }
//         q.push(p[i].k);
//     }
//     for(int i = n; i >= 1; i--){
//         if(p[i].t < b){
//             lb = i;
//             break;
//         }
//     }
//     ll res = 0;
//     for(int i = la; i <= lb; i++){
//         q.push(p[i].k);
//     }
//     for(int i = 1; i <= b-a; i++){
//         res += q.top();
//         //cout<<q.top()<<" ";
//         q.pop();
//     }
//     //cout<<'\n';
//     cout<<res;
// }

// int main()
// {
//     cin.tie(NULL); cout.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     freopen("PEACH.inp","r",stdin);
//     freopen("PEACH.out","w",stdout);
//     cin>>n>>a>>b;
//     for(int i = 1; i <= n; i++){
//         cin>>p[i].t>>p[i].k;
//     }
//     solve();
// }