#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b, cong, tru;
string sumstring(string x, string y){
    int nho = 0;
    string  ans;
    ll t, l = x.size()-1;
    ans.resize(l+1);
    while(y.size() < x.size())
        y = "0"+y;
    for(int i = l; i >= 0; i--){
         t = (x[i] - '0') + (y[i] - '0') + nho;
         if(t >= 10){
            nho = 1;
            t = t%10;
         }
         else
            nho = 0;
         ans[i] = t + '0';
    }
    if(nho == 1)
        ans = "1"+ans;
    return ans;
}
int main()
{
    freopen("BIGNUM.inp","r",stdin);
    freopen("BIGNUM.out","w",stdout);
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>a;
	cin>>b;
	while(b.size()<a.size())
        b = "0"+b;
    long long  n = a.size(), t, h;
    cong.resize(n);
    tru.resize(n);
    int nho = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        t = (a[i]-'0')+(b[i]-'0')+nho;
        if(t >= 10)
        {
            nho = 1;
            t = t%10;
        }
        else
            nho = 0;
        cong[i] = t + '0';
    }
    if(nho == 1)
        cout<<"1";
    cout<<cong<<'\n';
    int muon = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] - '0' < (b[i] - '0') + muon)
        {
            h = ((a[i] - '0') + 10) - (b[i] - '0') - muon;
            muon = 1;
        }
        else
        {
            h = (a[i] - '0') - (b[i] - '0') - muon;
            muon = 0;
        }
        tru[i] = h + '0';
    }
    int i = 0;
    while(tru[i]=='0' && i < n - 1)
        i++;
    for(int j = i; j <= n - 1; j++)
        cout<<tru[j];
}
