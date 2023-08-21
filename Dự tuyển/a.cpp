#include<bits/stdc++.h>
using namespace std;
#define Nmax 1000001
#define Tmax 10001
#define str string
#define endl '\n'
#define fort(i,d,c) for(int i=d;i<=c;i++)
#define forl(i,c,d) for(int i=c;i>=d;i--)
#define fi first
#define se second
#define TASK N13
string a , b;
int n;
long long f[20][2][2][2];
long long cal(int i , bool oka , bool okb , bool pre)
{
    if(i >= n) return 1;
    if(f[i][oka][okb][pre] != -1) return f[i][oka][okb][pre];
    f[i][oka][okb][pre] = 0;
    //cnt++;
    for (int j = '0' ; j <= '9' ; j++)
    {
    if((j >= a[i] || oka) && (j <= b[i] || okb) && (j !='3' || !pre))
    f[i][oka][okb][pre] += cal(i + 1 , oka || j > a[i] , okb || j < b[i] , j == '1');
    }
    return  f[i][oka][okb][pre];
}
main(){
    freopen("N13.INP","r",stdin);
    freopen("N13.OUT","w",stdout);
    while(cin >> a >> b)
    {
    memset(f , -1 , sizeof(f));
    n = b.size();
    while(a.size() != b.size())
    {
        a = '0' + a;
    }
    cout << cal(0 , false , false ,false) << endl;
    }
}