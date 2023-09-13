#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
long long n, k, S = 0, c[1000021];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout.tie(NULL);
    // freopen("GAS.INP","r",stdin);
    // freopen("GAS.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(long long i = 1; i <= n; i++) {
        while(!dq.empty() && c[dq.back()] >= c[i])
            dq.pop_back();
        while(!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();
        dq.push_back(i);
        if(i >= 1)
            S += c[dq.front()];
    }
    cout << S;
}