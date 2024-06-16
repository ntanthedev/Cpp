#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    s=' '+s;
    vector<ll>save;
    save.push_back(0LL);
    unordered_map<string,ll>M;
    ll d=0,dd=0;
    string t,emp;
    for(ll i=1;i<=n;i++)
    {
        if(s[i]=='(') d++;
        else d--;
        t.push_back(s[i]);
        if(!d)
        {
            if(!M[t])
            {
                dd++;
                M[t]=dd;
                save.push_back(dd);
            }
            else save.push_back(M[t]);
            t=emp;
        }
    }
    n=save.size();
    n--;
    for(ll i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            ll sas=2;
            for(ll j=1;j<=i;j++)
            {
                for(ll k=j+i+1;k<=n;k+=i)
                {
                    if(save[k]!=save[j])
                    {
                        sas--;
                    }
                }
            }
            if(sas>0)
            {
                
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tests=1;
    while(tests--) {
        solve();
    }
}

//for(int i = 1; i <= n; i++) cin >> a[i] >> a[j];