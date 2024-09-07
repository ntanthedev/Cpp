//created in 2024-08-26-10.10.54 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3e3 + 3;

int n;
int a[N], mmax[N];
ll dp[4], sumarr = 0, max_s;
string group;
int cnt[4] = {0, 0, 0, 0};


void cal(int i) {
    if(i > 3 * n) {
        if(dp[1] == dp[2] && dp[2] == dp[3] && dp[3] == sumarr / 3) {
            cout << group;
            exit(0);
        }
        return;
    }

    for(int j = 1; j <= 3; j++) {
        if(cnt[j] >= n || dp[j] + a[i] > sumarr / 3)
            continue;
        if(cnt[j] == n - 2 && dp[j] + a[i] + mmax[i] < sumarr / 3)
            continue;
        if(cnt[j] == n - 1 && dp[j] + a[i] < sumarr / 3)
            continue;
        cnt[j]++;
        dp[j] += a[i];
        group.push_back(char(j + '0'));
        cal(i + 1);
        group.pop_back();
        cnt[j]--;
        dp[j] -= a[i];
    }
}

void sub3() {
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    group.clear();
    mmax[3 * n + 1] = 0;
    for(int i = 3 * n; i >= 1; i--) {
        mmax[i] = max(mmax[i + 1], a[i]);
    }
    cal(1);
    cout << '\n';
}

void sub4() {
    int j = 1, k = 1;
    string ans;
    for(int i = 3 * n; i >= 1; i -= 3) {
        if(j) {
            ans.push_back('1');
            ans.push_back('2');
            ans.push_back('3');
        }
        else {
            ans.push_back('3');
            ans.push_back('2');
            ans.push_back('1');
        }
        j ^= 1;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("DIVSEQ.inp","r",stdin);
    freopen("DIVSEQ.out","w",stdout);

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        bool check_sub_4 = 1;
        for(int i = 1; i <= 3 * n; i++) {
            cin >> a[i];
            sumarr += a[i];
            if(a[i] != i)
                check_sub_4 = 0;
        }
        if(check_sub_4)
            sub4();
        else
            sub3();
        sumarr = 0;
    }
}


/*
dp[i][j]
xet den vi tri i va chon a[i] vao nhom j
if(dp[i - 1][j] + a[i] <= sumarr/3)
    dp[i][j] = dp[i - 1][j] + a[i];
else
    ...//bo qua



1 2 3 4 5 6 7 8 9 10 11 12
12 7 6 1
11 8 5 2
10 9 4 3
1 5 9
2 6 7
3 4 8
*/
