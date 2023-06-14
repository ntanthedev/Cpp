#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
string s;
map<char, ll>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);
    getline(cin,s);
    for(int i = 0; i < s.size(); i++){
        M[s[i]]++;
    }
    for(int i = 'A'; i <= 'Z'; i++)
        cout<<M[i]<<'\n';
    for(int i = 'a'; i <= 'z'; i++)
        cout<<M[i]<<'\n';
    for(int i = '0'; i <= '9'; i++)
        cout<<M[i]<<'\n';
}