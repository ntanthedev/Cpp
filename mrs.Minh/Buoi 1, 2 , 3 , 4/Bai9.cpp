#include<bits/stdc++.h>
using namespace std;
long long n;
bool b[1000009];
void sang(long long n)
{
    memset(b,true,sizeof(b));
    b[0] = b[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(b[i]){
            for(int j = i*i; j <= n; j+=i)
                b[j] = false;
        }
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai9.inp","r",stdin);
    freopen("Bai9.out","w",stdout);
    cin>>n;
    sang(n);
    long long ans = int(sqrt(n));
    if(b[ans])
        cout<<"YES";
    else
        cout<<"NO";
}
