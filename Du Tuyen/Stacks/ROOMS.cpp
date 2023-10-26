#include <bits/stdc++.h>
using namespace std;
struct ii 
{
    int val;  
    int kind;  
    int conf;
};
ii ID[1000001];
int n, u, v;
int m; 
int meet[1000001];
vector<int>
    room[1000001];
stack<int> s;

bool cmp(const ii& x, const ii& y) {
    if(x.val == y.val)
        return x.kind > y.kind;
    else
        return x.val < y.val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ROOMS.inp", "r", stdin);
    freopen("ROOMS.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        ID[i * 2 - 1].val = u;
        ID[i * 2].kind = 0;
        ID[i * 2 - 1].conf = i;

        ID[i * 2].val = v;
        ID[i * 2].kind = 1;
        ID[i * 2].conf = i;
    }
    for(int i = n; i >= 1; i--)
        s.push(i);  

    sort(ID + 1, ID + 2 * n + 1, cmp);

    for(int i = 1; i <= 2 * n; i++) {
        if(ID[i].kind == 0) 
        {
            int meetNum = s.top();
            s.pop();                     
            meet[ID[i].conf] = meetNum;  

            room[meetNum].push_back(
                ID[i].conf);  
            m = max(m, meetNum);  
        } else
            s.push(meet[ID[i].conf]);  
    }
    cout << m << '\n';
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < room[i].size(); j++)
            cout << room[i][j] << " ";
        cout << '\n';
    }
}