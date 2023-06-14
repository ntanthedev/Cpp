#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
vector<ll>a;
map<ll, ll>b;
ll n, i, j, gmax = LLONG_MIN, vt;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>j;
        a.push_back(j);
        b[j]++;
    }
    for(auto i : b){
        if(i.second() > gmax){
            gmax = i.second;
            vt = i.first;
        }
    }
    for(int i = 1; i <= gmax; i++)
        a.push_back(vt);
    for(int i  = 0; i < vt + gmax; i=+){
        if(i < n){
            if(a[i] != vt)
                cout<<a[i]<<" ";
        }
        else
            cout<<a[i]<<" ";
    }
}