#include<bits/stdc++.h>
#define tag "DIGITS"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll n, ans = 0;
void solve(){    
    for(int a = 1; a <= 9; a++)
        for(int b = 1; b <= 9; b++)
            for(int c = 1; c <= 9; c++)
                for(int d = 1; d <= 9; d++)
                    for(int e = 1; e <= 9; e++)
                        for(int f = 1; f <= 9; f++)
                            for(int g = 1; g <= 9; g++){
                                if(a*b*c - 62*d + e*f*g == n)  
                                    ans++; 
                            }
    cout<<ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n;
    solve();
}