#include<bits/stdc++.h>
#define int long long
const int N=5e4+10;
#define M 1e18
using namespace std;
int n,m,a[N],l[4*N],h[4*N],maxn[4*N],s1,x,y,z,lazy[4*N];
void update(int x, int a, int b, int i, int j, int k)
{
    if(lazy[x]!=0)
    {
        maxn[x]+=lazy[x];
        if(a!=b)
        {
            lazy[2*x]+=lazy[x];
            lazy[2*x+1]+=lazy[x];
        }
        lazy[x]=0;
    }   
    if(a>b || a>j || b<i) return ;
    if(i <= a && b <= j)
    {
        maxn[x]+=k;
        if(a!=b)
        {
            lazy[2*x]+=k;
            lazy[2*x+1]+=k;
        }
        return ;
    }
    int mid=(a+b)/2;
    update(2*x,a,mid,i,j,k);
    update(2*x+1,mid+1,b,i,j,k);
    maxn[x]=max(maxn[2*x],maxn[2*x+1]);
}
int query(int x,int a,int b,int i, int j)
{
    if(a>b || a>j || b<i) return (-M);
    if(lazy[x]!=0)
    {
        maxn[x]+=lazy[x];
        if(a!=b)
        {
            lazy[2*x]+=lazy[x];
            lazy[2*x+1]+=lazy[x];
        }
        lazy[x]=0;
    }
    if(a>=i && b<=j) return maxn[x];
    int q1=query(2*x,a,(a+b)/2,i,j);
    int q2=query(2*x+1,(a+b)/2+1,b,i,j);
    return max(q1,q2);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("QMAX2.INP","r",stdin);
    //freopen("QMAX2.OUT","w",stdout);
    cin>>n>>m;
    memset(lazy,0,sizeof(lazy));
    for(int i=1;i<=m;i++)
    {
        cin>>s1;
        if(s1==0)
        {
            cin>>x>>y>>z;
            update(1,1,n,x,y,z);
        }
        else
        {
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<"\n";
        }
    }
}
/*
┌───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│ │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│ ┌┐ ┌┐ ┌┐
└───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘ └┘ └┘ └┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │Num│ / │ * │ - │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│ Shift    │     │ ↑ │     │ 1 │ 2 │ 3 │   │
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E │
│ Ctrl│ Win│ Alt│         Space         │ Alt│ Win│Menu│Ctrl│ │ ← │ ↓ │ → │ │ 0 │ . │←─┘│   │
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
*/