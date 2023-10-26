//Write by Jethro_
//------------------------
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;
long long n, Hash[N];
map<long long, int> M;
string s[N];
set<int> ss;
set<int>::iterator p;
void add() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
        ss.insert(i);
    }
}
void solve() {

    int i = 0;
    while(i <= 1e6) {
        int d = 0;
        vector<int> del;

        for(p = ss.begin(); p != ss.end(); ++p) {
            int it = p;
            if(s[it].size() < i + 1 ) {
                del.push_back(it);
            }else {
                Hash[it] = (Hash[it]*311 + s[it][i] - 'a')%mod;
                M[Hash[it]]++;
            }
        }

        for(int j = 0; j < del.size(); ++j) {
            ss.erase(del[j]);
        }
        del.clear();
        bool kt = false;

          for(p = ss.begin(); p != ss.end(); ++p) {
            int it = *p;
            if(M[Hash[it]] == 1) {
                del.push_back(it);
            }else {
                kt = true;
            }
        }
        if(kt == false) {
            cout << i + 1;
            exit(0);
        }
        for(int j = 0; j < del.size(); ++j) {
            ss.erase(del[j]);
        }
        M.clear();
        ++i;
    }
}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("GEN.inp", "r", stdin);
    freopen("GEN.out", "w", stdout);
    add();
    solve();
}