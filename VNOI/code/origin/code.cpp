// problem "a"
// created in 19:57:14 - Mon 03/03/2025

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 9;

int n, K;
int a[N];

struct sub1 {
    int ans = 0;

    sub1() {
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                int gmax = 0, gmin = INT_MAX;

                for(int k = i; k <= j; k++)
                    gmax = max(gmax, a[k]), gmin = min(gmin, a[k]);

                if(gmax - gmin <= K)
                    ans = max(ans, j - i + 1);
            }
        }

        cout << ans;
    }
};

struct sub2 {
    sub2() {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int gmax = 0, gmin = INT_MAX;
            for(int j = i; j <= n; j++) {
                gmax = max(gmax, a[j]);
                gmin = min(gmin, a[j]);
                if(gmax - gmin <= K)
                    ans = max(ans, j - i + 1);
            }
        }

        cout << ans;
    }
};

struct sub3 {
    multiset<int> m;
    int ans = 1;

    sub3() {
        int l = 1, r = 1;
        m.insert(a[1]);

        while(r <= n) {
            if(*m.rbegin() - *m.begin() <= K) {
                ans = max(ans, r - l + 1);
                r++;
                m.insert(a[r]);
            } else {
                m.erase(m.find(a[l]));
                l++;
            }
        }

        cout << ans;
    }
};

struct sub4 {

    deque<int> max_dq, min_dq;
    int ans = 0;

    sub4() {
        int l = 1;
        for (int r = 1; r <= n; r++) {
            while (!max_dq.empty() && a[max_dq.back()] <= a[r])
                max_dq.pop_back();
            max_dq.push_back(r);
            
            while (!min_dq.empty() && a[min_dq.back()] >= a[r])
                min_dq.pop_back();
            min_dq.push_back(r);
            
            while (l <= r && a[max_dq.front()] - a[min_dq.front()] > K) {
                l++;
                while (!max_dq.empty() && max_dq.front() < l)
                    max_dq.pop_front();
                while (!min_dq.empty() && min_dq.front() < l)
                    min_dq.pop_front();
            }
            
            ans = max(ans, r - l + 1);
        }
        
        cout << ans;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> K;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    delete new sub4();

    // if(n <= 1e2) 
    //     new sub1();
    // else if(n <= 1e3)
    //     new sub2();
    // else if(n <= 1e5)
    //     new sub3();
    // else 
    //     new sub4();
}