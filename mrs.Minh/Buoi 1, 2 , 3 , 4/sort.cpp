#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll dx = 0, dt = 0, dh = 0, n;
char s;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("sort.inp","r",stdin);
    freopen("sort.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>s;
        if(s == 'H')
            dh++;
        if(s == 'T')
            dt++;
        if(s == 'X')
           dx++;
    }
    for(int i = 1; i <= dx; i++)
        cout<<"X"<<" ";
    for(int i = 1; i <= dh; i++)
        cout<<"H"<<" ";
    for(int i = 1; i <= dt; i++)
        cout<<"T"<<" ";
}