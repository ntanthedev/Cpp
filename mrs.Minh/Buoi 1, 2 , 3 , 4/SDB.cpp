#include<bits/stdc++.h>
using namespace std;
long long a, b, t;
bool slove(long long x)
{
    int dem = 0;
    for(int i = 1; i <= sqrt(x); i++){
        if(x%i == 0){
            dem++;
            int j = x/i;
            if(j != i)
                dem++;
        }
        if(dem > 9)
            break;
    }
    if(dem == 9)
        return true;
    else
        return false;
}
int main()
{
    cin.tie(0); cout.tie(0);
    freopen("SDB.inp","r",stdin);
    freopen("SDB.out","w",stdout);
    cin>>t; int dem;
    for(int q = 1; q <= t;  q++){
        cin>>a>>b; dem = 0;
        while(a%3 != 0)
            a++;
        for(int i = a; i <= b; i+=3){
            if(slove(i) && i%3 == 0)
                dem++;
        }
        cout<<dem<<'\n';
    }
}
