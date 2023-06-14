#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e3+5;
vector<string> a;
bool cmp(string x, string y){
    if(x[0] > y[0])
        return x < y;
    if(x[0] < y[0])
        return y < x;
    if(x[0] == y[0]){
        ll c = stoll(x), d = stoll(y);
        if(c > d)
            return x < y;
        else
            return y < x;
    }
}
void solve(){
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < a.size(); i++){
        cout<<a[i];
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    a.reserve(101);
    string s;
    while(cin>>s){
        a.push_back(s);
    }
    solve();
}
