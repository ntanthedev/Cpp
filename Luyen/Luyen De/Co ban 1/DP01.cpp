
#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, gmax = LLONG_MIN, vt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DP01.inp","r",stdin);
    freopen("DP01.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] > gmax){
            gmax = a[i];
            vt = i;
        }
    }
    cout<<vt;
}
/*
#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, scm = LLONG_MAX - 1, flag = 0, gmax = LLONG_MAX, vt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DP05.inp","r",stdin);
    freopen("DP05.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] < gmax)
            gmax = a[i];
    }
    for(int i = 1; i <= n; i++){
        if(a[i] > gmax && a[i] < scm){
            scm = a[i];
            flag = 1;
        }
    }
    if(flag == 0)
        cout<<"NO";
    else
        cout<<scm;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, b[1000009], flag = 0, gmax = LLONG_MAX, vt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DP04.inp","r",stdin);
    freopen("DP04.out","w",stdout);
    cin>>n;
    memset(b, 0, n);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[a[i]]++;
        if(a[i] < gmax){
            gmax = a[i];
        }
    }
    cout<<b[gmax];
}*/
/*
#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, flag = 0, gmax = LLONG_MAX, vt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DP03.inp","r",stdin);
    freopen("DP03.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] < gmax && a[i] > 0 && a[i]%2 == 0){
            gmax = a[i];
            vt = i;
            flag = 1;
        }
    }
    if(flag == 0)
        cout<<-1;
    else
        cout<<vt;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, flag = 0, gmax = LLONG_MAX, vt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DP02.inp","r",stdin);
    freopen("DP02.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] < gmax && a[i] > 0){
            gmax = a[i];
            vt = i;
            flag = 1;
        }
    }
    if(flag == 0)
        cout<<-1;
    else
        cout<<vt;
}*/
