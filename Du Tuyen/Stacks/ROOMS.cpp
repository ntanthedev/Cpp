#include <bits/stdc++.h>
using namespace std;

struct pt {
    int id;
    int s, f;
};

bool cmp(pt a, pt b) {
    if(a.s != b.s)
        return a.s < b.s;
    return a.f < b.f;
}

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("ROOMS.INP", "r")) {
        freopen("ROOMS.INP", "r", stdin);
        freopen("ROOMS.OUT", "w", stdout);
    }

    int n;
    cin >> n;

    vector<pt> a(n);
    for(int i = 0; i < n; ++i) {
        a[i].id = i + 1;
        cin >> a[i].s >> a[i].f;
    }

    sort(a.begin(), a.end(), cmp);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    priority_queue<int, vector<int>, greater<int>> free;

    vector<vector<int>> rooms;

    int ans = 0;

    for(auto& conf: a) {
        while(!pq.empty() && pq.top().first <= conf.s) {
            free.push(pq.top().second);
            pq.pop();
        }

        int cur;    

        if(!free.empty()) {
            cur = free.top();
            free.pop();
        } else {
            ans++;
            cur = ans;
            rooms.resize(ans + 1);
        }

        rooms[cur].push_back(conf.id);

        pq.push({conf.f, cur});
    }

    cout << ans << "\n";
    for(int i = 1; i <= ans; ++i) {
        for(int j = 0; j < rooms[i].size(); ++j) {
            cout << rooms[i][j] << " ";
        }
        cout << "\n";
    }
}