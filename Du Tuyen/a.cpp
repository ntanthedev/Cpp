#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,a,b;
vector<ll>nt(4000021);
vector<ll>ntt;
ll dem=0;
void sieve()
{
    for(ll i=1;i<=4000000;i++) nt[i]=i;
    for(ll i=2;i<=4000000;i++)
    {
        if(nt[i]==i)
        {
            ntt.push_back(i);
            dem++;
            for(ll j=i*i;j<=4000000;j+=i) nt[j]=i;
        }
    }
}
void sub1() {
    ll ans=0;
    for(ll i=2;i<=n;i++)
    {
        if(nt[i]==i)
        {
            if(i*i<=n) ans++;
        }
    }
    cout<<ans;
}
void sub2()
{
    ll ans=0;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(nt[i]==i)
        {
            if(i*i<=n && a) ans++;
            if(i*i*i<=n) ans++;
            if(i*i*i*i<=n) ans++;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=1e3) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    cout<<ans;
}
void sub3()
{
    ll ans=0;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(i*i*i>=1e12+21) break;
        if(nt[i]==i)
        {
            //if(i*i<=n) ans++;
            if(i<=(1e4+21) && i*i*i<=n && a<=3) ans++;
            if(i<=(1e3+21) && i*i*i*i<=n && a<=4) ans++;
            if(a<=5 && i<=(5e2+21) && i*i*i*i*i<=n) ans++;
            if(i<=(1e2+21)    && i*i*i*i*i*i<=n && a<=6) ans++;
        }
    }
    if(a<=4)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(1e3+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    }
    if(a<=6)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(5e2+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(5e2+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    }
    cout<<ans;
}
void sub4()
{
    ll ans=0;
    for(ll i=2;i<=sqrt(n);i++)
    {
        //if(i*i*i>=(1e12+21)) break;
        if(nt[i]==i)
        {
            if(i*i<=n && a<=2) ans++;
            if(i<=(1e4+21) && i*i*i<=n && a<=3 && b>=3) ans++;
            if(i<=(1e3+21) && i*i*i*i<=n && a<=4 && b>=4) ans++;
            if(a<=5 && i<=(5e2+21) && i*i*i*i*i<=n && b>=5) ans++;
            if(i<=(1e2+21)    && i*i*i*i*i*i<=n && a<=6 && b>=6) ans++;
            if(a<=7 && i<=80  && i*i*i*i*i*i*i<=n && b>=7) ans++;
            if(a<=8 && i<=50  && i*i*i*i*i*i*i*i<=n && b>=8) ans++;
            if(a<=9 && i<=30  && i*i*i*i*i*i*i*i*i<=n && b>=9) ans++;
            if(a<=10 && i<=20 && i*i*i*i*i*i*i*i*i*i<=n && b>=10) ans++;
            if(a<=11 && i<=16 && i*i*i*i*i*i*i*i*i*i*i<=n && b>=11) ans++;
            if(a<=12 && i<=11 && i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=12) ans++;
            if(a<=13 && i<=10 && i*i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=13) ans++;
            if(a<=14 && i<=9 &&  i*i*i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=14) ans++;
            if(a<=15 && i<=8 &&  i*i*i*i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=15) ans++;
            if(a<=16 && i<=7 &&  i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=16) ans++;
            if(a<=17 && i<=6 &&  i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=17) ans++;
            if(a<=18 && i<=6 &&  i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=18) ans++;
            if(a<=19 && i<=6  && i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=19) ans++;
            if(a<=20 && i<=6  && i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i<=n && b>=20) ans++;
        }
    }
    if(a<=4 && b>=4)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(1e3+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    }
    if(a<=6 && b>=6)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(5e2+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(5e2+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    }
    if(a<=8 && b>=8)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(1e2+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
            //cout<<ntt[i]<<" "<<ntt[j]<<'\n';
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(1e2+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
            //cout<<ntt[i]<<" "<<ntt[j]<<'\n';
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(1e2+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(1e3+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]<=n) ans++;
                else break;
                //cout<<ntt[i]<<" "<<ntt[j]<<" "<<ntt[k]<<'\n';
            }
        }
    }
    }
    if(a<=10 && b>=10)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=80) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=80) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    }
    if(a<=14 && b>=14)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    }
    if(a<=9 && b>=9)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=(1e2+21)) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    }
    if(a<=12 && b>=12)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]<=n) ans++;
            else break;
        }
    } 
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=80) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=80) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }  
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=80) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(1e3+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]<=n) ans++;
                else break;
                //cout<<ntt[i]<<" "<<ntt[j]<<" "<<ntt[k]<<'\n';
            }
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=80) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(5e2+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[k]*ntt[j]*ntt[j]<=n) ans++;
                else break;
            }
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=80) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(5e2+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
                else break;
            }
        }
    }
    }
    if(a<=15 && b>=15)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    }
    if(a<=16 && b>=16)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=16) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=16) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[i]<=n) ans++;
            else break;
        }
    } 
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(1e3+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]<=n) ans++;
                else break;
            }
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(1e2+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[k]*ntt[k]*ntt[j]*ntt[j]<=n) ans++;
                else break;
                //cout<<ntt[i]<<" "<<ntt[j]<<" "<<ntt[k]<<'\n';
            }
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(1e2+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
                else break;
            }
        }
    } 
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(1e2+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[k]>=(1e3+21)) break;
                for(ll l=k+1;l<dem;l++)
                {
                    if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]*ntt[l]*ntt[l]<=n && ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]*ntt[l]*ntt[l]>0) ans++;
                    else break;
                    //cout<<ntt[i]<<" "<<ntt[j]<<" "<<ntt[k]<<" "<<ntt[l]<<"\n";
                }
            }
        }
    } 
    }
    if(a<=18 && b>=18)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=14) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=14) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]<=n) ans++;
            else break;
        }
    } 
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[i]*ntt[i]<=n) ans++;
            else break;
        }
    } 
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(5e2+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[k]*ntt[j]*ntt[j]<=n) ans++;
                else break;
            }
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(1e2+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[k]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
                else break;
            }
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=50) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(5e2+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
                else break;
            }
        }
    } 
    }
    if(a<=20 && b>=20)
    {
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=11) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=11) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[i]<=n) ans++;
            else break;
        }
    } 
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
            else break;
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[i]*ntt[j]*ntt[i]*ntt[i]*ntt[i]*ntt[j]*ntt[j]*ntt[i]*ntt[j]<=n) ans++;
            else break;
        }
    } 
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=(1e3+21)) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]<=n && ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]>0) ans++;
                else break;
                //cout<<ntt[i]<<" "<<ntt[j]<<" "<<ntt[k]<<'\n';
            }
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=80) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[k]*ntt[k]*ntt[k]*ntt[j]*ntt[j]<=n) ans++;
                else break;
                //cout<<ntt[i]<<" "<<ntt[j]<<" "<<ntt[k]<<'\n';
            }
        }
    }
    for(ll i=0;i<dem;i++)
    {
        if(ntt[i]>=30) break;
        for(ll j=i+1;j<dem;j++)
        {
            if(ntt[j]>=80) break;
            for(ll k=j+1;k<dem;k++)
            {
                if(ntt[i]*ntt[i]*ntt[k]*ntt[k]*ntt[j]*ntt[j]*ntt[j]*ntt[j]*ntt[j]<=n) ans++;
                else break;
                //cout<<ntt[i]<<" "<<ntt[j]<<" "<<ntt[k]<<'\n';
            }
        }
    }  
    }
    cout<<ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    //cout<<dem;
    cin>>n>>a>>b;
    if(n<=1e6 && b==2 && a==2) sub1();
    else if(n<=4e6 && b==4 && a==2) sub2();
    else if(b==6) sub3();
    else sub4();
}
//---writer---
// Yukatou Arimotou
// Yumesekai
// daisuki dayo, PEA-chan ❤
// animeizdabezt
// email: anime2152006@gmail.com
// Katou Megumi ❤
// Saekano ❤
// Minami - Eternal blue
// Minami - Ame wo matsu
// Truong mam non Van Yen
// Truong tieu hoc Nam Ha
// Truong THCS Le Van Thiem - 3K33
// Truong THPT Chuyen Ha Tinh - T1K31
/*
▓██   ██▓ █    ██  ███▄ ▄███▓▓█████   ██████ ▓█████  ██ ▄█▀▄▄▄       ██▓
▒██  ██▒ ██  ▓██▒▓██▒▀█▀ ██▒▓█   ▀ ▒██    ▒ ▓█   ▀  ██▄█▒▒████▄    ▓██▒
▒██ ██░▓██  ▒██░▓██    ▓██░▒███   ░ ▓██▄   ▒███   ▓███▄░▒██  ▀█▄  ▒██▒
░ ▐██▓░▓▓█  ░██░▒██    ▒██ ▒▓█  ▄   ▒   ██▒▒▓█  ▄ ▓██ █▄░██▄▄▄▄██ ░██░
░ ██▒▓░▒▒█████▓ ▒██▒   ░██▒░▒████▒▒██████▒▒░▒████▒▒██▒ █▄▓█   ▓██▒░██░
██▒▒▒ ░▒▓▒ ▒ ▒ ░ ▒░   ░  ░░░ ▒░ ░▒ ▒▓▒ ▒ ░░░ ▒░ ░▒ ▒▒ ▓▒▒▒   ▓▒█░░▓
▓██ ░▒░ ░░▒░ ░ ░ ░  ░      ░ ░ ░  ░░ ░▒  ░ ░ ░ ░  ░░ ░▒ ▒░ ▒   ▒▒ ░ ▒ ░
▒ ▒ ░░   ░░░ ░ ░ ░      ░      ░   ░  ░  ░     ░   ░ ░░ ░  ░   ▒    ▒ ░
░ ░        ░            ░      ░  ░      ░     ░  ░░  ░        ░  ░ ░
░ ░
*/