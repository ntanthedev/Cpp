#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll l, m, x[50], sum;
string s;
bool flag;
void output(){
    for(int i = 0; i <= l; i++){
        if(x[i]==0)
            cout<<"-";
        else
            cout<<"+";
        cout<<(s[i]-'0');
    }
}
void check(){
    sum = 0;
    for(int i = 0; i <= l; i++){
        if(x[i] == 1)
            sum += (s[i]-'0');
        else
            sum -= (s[i]-'0');
    }
    if(sum == m && flag == true){
        output();
        flag = false;
    }
}
void tim(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == l)
            check();
        else
            tim(i+1);
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s>>m;
    flag = true;
    l = s.size() - 1;
    tim(0);
}