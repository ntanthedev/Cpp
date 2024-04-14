//problem "a"
//created in 09:08:07 - Sun 14/04/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;
typedef pair<int, int> ii;

priority_queue<ii> q1;
priority_queue<ii, vector<ii> , greater<ii>> q;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    for(int i = 1; i <= 5; i++) {
        int u, v;
        cin >> u >> v;
        q1.push({u, v});
        q.push({u, v});
    }
    while(!q.empty()) {
        cout << q.top().first << " " << q.top().second << '\n';
        q.pop();
    }
    cout << "___________________\n";
    while(!q1.empty()) {
        cout << q1.top().first << " " << q1.top().second << '\n';
        q1.pop();
    }
    
}