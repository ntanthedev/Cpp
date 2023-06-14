#include<bits/stdc++.h>
#define tag "ATM"
#define ll long long 
const int N = 1e2+9;
using namespace std;
int a[N], n, S, f[N];
bool flag = false;
int read(){
    bool neg = false;
    char c = getchar();
    for(; c < '0' || '9' < c; c = getchar())
        if(c == '-') neg = !neg;
    int value =  0;
    while('0' <= c && c <= '9')
        value = (value << 3) + (value << 1) + c - '0', c = getchar();
    return neg ? value : -value;
}
void check(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i]*f[i];
    }
    if(sum == S){
        flag = true;
        for(int i = 1; i <= n; i++)
            if(f[i]) cout<<a[i]<<" ";
    }
}
void solve(int x){
    for(int i = 0; i <= 1; i++){
        if(flag)
            break;
        f[x] = i;
        if(x == n)
            check();
        else
            solve(x+1);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> S;
    for(int i = 1; i <= n; i++)
        cin >> a[i]; 
    solve(1);
}