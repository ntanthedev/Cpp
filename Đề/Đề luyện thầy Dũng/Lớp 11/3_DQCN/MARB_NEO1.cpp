#include <bits/stdc++.h>
using namespace std;

const int N=300+5;

int s,n,m;
int a[N];
long long f[N][N][N];

long long Cal(int i,int sum,int pre)
{
    
  //Dùng i làm NEO đạt 95 điểm, lời gọi hàm lúc này là:Cal(1,0,0); 
  //Sinh ra các nghiệm xấu như: 0+0+0....+1+99 =100, làm quá thời gian
  if(i>n)
         if (sum==s) return 1;
         else return 0; 
    
   if (f[i][sum][pre]!=-1)        return f[i][sum][pre];

  f[i][sum][pre]=0;    

  for (int j=pre;j<=min(m,s-sum);j++)
    {
        f[i][sum][pre]+=Cal(i+1,sum+j,j);
    }

    return f[i][sum][pre];

}

int main()
{
    freopen("MARB.inp","r",stdin);
    freopen("MARB.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s>>n>>m;
    memset(f,-1,sizeof(f));
    cout<<Cal(1,0,0);
}
