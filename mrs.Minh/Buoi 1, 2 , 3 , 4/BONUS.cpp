#include<bits/stdc++.h>
using namespace std;
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
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
