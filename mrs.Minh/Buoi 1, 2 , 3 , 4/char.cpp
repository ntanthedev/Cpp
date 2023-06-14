#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
string s;
ll gmax, M[N];
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("char.inp","r",stdin);
    freopen("char.out","w",stdout);
    getline(cin,s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9')
            M[int(s[i])]++;
            gmax = max(gmax, M[int(s[i])]);
    }
    for(int i = 48; i <= 58; i++)
        if(gmax == M[i]){
            cout<<char(i);
            break;
        }
}