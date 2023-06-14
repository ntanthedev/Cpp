#include<bits/stdc++.h>
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll n, x, res = 0;
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("SUMAVR.inp","r",stdin);
  freopen("SUMAVR.out","w",stdout);
  cin>>n;
  for(int i = 1; i <= n; i++){
    cin>>x;
    cout<<x*i - res<< " ";
    res += x*i - res;
  }
}
