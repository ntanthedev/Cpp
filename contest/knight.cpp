#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll ax,ay, bx,by;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>ax>>ay>>bx>>by;
    int n = ay+2, s = ay-2, e = ax+2, w = ax-2;
    if(n == by && (ax+1 == bx || ax-1 == bx))
        cout<<"Yes";
    else if(s == by && (ax+1 == bx || ax-1 == bx))
        cout<<"Yes";
    else if(e == bx && (ay+1 == by || ay-1 == by))
        cout<<"Yes";
    else if(w == bx && (ay+1 == by || ay-1 == by))
        cout<<"Yes";
    else
        cout<<"No";
}