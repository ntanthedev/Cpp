#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
string n;
bool c3(string s){
    ll res = 0;
    for(int i = 0; i < s.size(); i++){
        res += s[i] - '0';
    }
    if(res%3 == 0)
        return true;
    return false;
}
bool c5(string s){
    ll res = s.size() - 1;
    if(s[res] == '0' || s[res] == '5')
        return true;
    else
        return false;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("chiahet.inp","r",stdin);
    freopen("chiahet.out","w",stdout);
    cin>>n;
    if(c3(n) || c5(n)) 
        cout<<"YES";
    else
        cout<<"NO";
}