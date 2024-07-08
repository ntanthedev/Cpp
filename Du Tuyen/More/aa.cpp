// Source: https://ide.usaco.guide/O1BzYb_11ciS4NhGH0B
//help me debugs this pls :((
// i don't know what i wrong

#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second

using namespace std;

typedef pair<long long, long long> ii;

map<ii, ii> m;
set<ii> s;
int n, cnt = 0;

ii find_par(ii x) {
    return (m[x].fi < 0 ? x : m[x] = find_par(m[x]));
}

void merge_par(ii a, ii b) {
    a = find_par(a);
    b = find_par(b);

    if(a != b) {
        if(a.fi < b.fi)
            swap(a, b);
        --cnt;
        m[b].fi += m[a].fi;
        m[a] = b;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ii x;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x.fi >> x.se;
        if(m.count(x)) {
            cout << cnt << " ";
            continue;
        }
        m[x] = {-1LL, 0LL};
        ++cnt;

        vector<set<ii>::iterator> vt;
        auto r = s.lower_bound(x);
        ii newlr = x;
        while(r != s.end()) {
            if(x.se >= r->fi) {
                merge_par(x, *r);
                vt.push_back(r);
            }
            else 
                break;
            ++r;
        }     
        newlr.se = vt.back()->se;

        auto l = s.lower_bound(x);
        while(l != s.begin()) {
            --l;
            if(x.fi <= l->se) {
                merge_par(x, *l);
                vt.push_back(l);
            }
            else 
                break;
        }
        newlr.fi = vt.back()->fi;
        for(auto it : vt) 
            s.erase(it);

        cout << cnt << " ";
        s.insert(newlr);
    }
    
}