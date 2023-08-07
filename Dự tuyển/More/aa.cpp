#include<bits/stdc++.h>
//---definition----
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf pop_front
#define fi first
#define se second
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
const int N=1e6+21;
using namespace std;
//---function----
template <typename T> inline void read (T &x) 
{
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
//---variation---
ll n,x,S=0,d=0,h,k;
//---solution---
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>x;
    vector<ll>a(n+1),b(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++) 
    {
        cin>>b[i];
        S+=a[i]*b[i];
        if(a[i]>=b[i])
        {
        if(2*a[i]*b[i]+a[i]+b[i]>=2*h*k+k+h && a[i]*b[i]+a[i]>=h*k+h && a[i]*b[i]+a[i]>=k*h+k)
        {
            h=a[i],k=b[i];
        }
        }
        else
        {
            if(2*a[i]*b[i]+a[i]+b[i]>=2*h*k+k+h && a[i]*b[i]+b[i]>=h*k+h && a[i]*b[i]+b[i]>=k*h+k)
        {
            h=a[i],k=b[i];
        }
        }

    }
    S-=h*k;
    ll m=h+k+x;
    if(h+x<=k) S+=(h+x)*k;
    else if(k+x<=h) S+=h*(k+x);
    else if(m%2==0) S+=m*m/4;
    else S+=(m/2 +1)*(m/2);
    cout<<S;
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