#include<bits/stdc++.h>
//---definition----
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf pop_front
#define fi first
#define se second
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
const int N=1e6+21;
using namespace std;
//---function----
//---variation---
template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}
ll n,q,y,l,r;
//---solution---
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read(n), read(q);
    vector<ll>a(n+1);
    while(q--)
    {
        read(y), read(l), read(r);
        if(y==1)
        {
            ll x;
            read(x);
            a[l]^=x;
            ~x;
            a[r+1]^=x;
        }
        else if(y==2)
        {
            ll S=0;
            for(ll i=1;i<=n;i++)
            {
                a[i]^=a[i-1];
            }
            for(ll i=l;i<=r;i++)
            {
                S^=a[i];
            }
            for(ll i=1;i<=n;i++) a[i]=0;
                cout<<S<<'\n';
        }
    }
}
//---author---
// Yukatou Arimotou
// Yumesekai
// daisuki dayo, PEA-chan <3
// animeizdabezt
// email: anime2152006@gmail.com
// Katou Megumi <3
// Saekano <3
// Minami - Eternal blue
// Minami - Ame wo matsu
// Truong mam non Van Yen
// Truong tieu hoc Nam Ha
// Truong THCS Le Van Thiem - 3K33
// Truong THPT Chuyen Ha Tinh - T1K31
