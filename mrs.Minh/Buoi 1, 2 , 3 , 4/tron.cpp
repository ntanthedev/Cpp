#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
string s1, s2, s3;
ll M[N];
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("tron.inp","r",stdin);
    //freopen("tron.out","w",stdout);
    cin>>s1>>s2;
    for(int i = 0; i < s1.size(); i++){
        M[s1[i]]++;    
    }
    for(int i = 0; i < s2.size(); i++){
        M[s2[i]]++;
    }
    for(int i = 'Z'; i >= 'A'; i--){
        if(M[i] != 0)
        for(int j = 1; j <= M[i]; j++){
            cout<<char(i);
        }
    }
    for(int i = 'z'; i >= 'a'; i--){
        if(M[i] != 0)
        for(int j = 1; j <= M[i]; j++){
            cout<<char(i);
        }
    }
}