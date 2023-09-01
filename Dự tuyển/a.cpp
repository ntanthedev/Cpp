#include <bits/stdc++.h>
using namespace std;

const int LG = 18;
const int INF = 1e9;
struct Trie {
    struct Node {
        Node* child[2];
        int mn;

        Node() {
            for(int i = 0; i < 2; i++)
                child[i] = NULL;
            mn = INF;
        }
    };

    int cur;
    Node* root;
    Trie() : cur(0) { root = new Node(); };

    void add_number(int x) {
        Node* p = root;
        for(int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;
            if(p->child[c] == NULL)
                p->child[c] = new Node();

            p = p->child[c];
            p->mn = min(p->mn, x);
        }
    }

    int query(int x, int val) {
        Node* p = root;
        int res = 0;
        for(int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;
            if(p->child[c ^ 1] != NULL && p->child[c ^ 1]->mn <= val) {
                res += ((c ^ 1) << i);
                p = p->child[c ^ 1];
            } else {
                if(p->child[c] == NULL || p->child[c]->mn > val)
                    return -1;
                p = p->child[c];
                res += (c << i);
            }
        }
        return res;
    }
};

const int N = 1e5;
Trie tries[N + 5];
vector<int> d[N + 5];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i)
            d[j].push_back(i);
    }

    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int u;
            cin >> u;
            for(auto x: d[u])
                tries[x].add_number(u);
        } else {
            int x, k, s;
            cin >> x >> k >> s;

            if(x % k != 0)
                cout << "-1\n";
            else
                cout << tries[k].query(x, s - x) << "\n";
        }
    }
}