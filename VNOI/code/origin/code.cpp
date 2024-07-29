#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

vector<ll> ch[30];
bool pal[5009][5009];
str s;
ll q, ans[5009][5009];

void pal_check(ll a, ll b){
    if(a + 1 == b){
        pal[a][b] = true;
        return;
    }
    if(pal[a + 1][b - 1]){
        pal[a][b] = true;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> s;
    for(int j = 0; j < s.size(); j++){
        ll i = j + 1;
        pal[i][i] = true;
        if(!ch[s[j] - '0'].empty()){
            for(int o = ch[s[j] - '0'].size() - 1; o >= 0; o--){
                pal_check(ch[s[j] - '0'][o], i);
            }
        }
        ch[s[j] - '0'].push_back(i);
    }
    for(int i = 1; i <= s.size(); i++){
        for(int j = i; j <= s.size(); j++){
            ans[i][j] = ans[i][j - 1] + pal[i][j];
        }
    }
    cin >> q;
    while(q--){
        ll f, s, fans = 0;
        cin >> f >> s;
        for(int i = f; i <= s; i++){
            fans += ans[i][s];
        }
        cout << fans << '\n';
    }
}
/*
1  2  3  4  5  6
c  a  a  a  b  a
1  2  4  7  8  10
10 9  6  4  2  1

*/
