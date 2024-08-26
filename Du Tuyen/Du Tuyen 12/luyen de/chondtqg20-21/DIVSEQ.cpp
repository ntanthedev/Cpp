//created in 2024-08-26-10.10.54 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e3 + 3;

int n;
int a[N];
ll dp[N][4], sumarr = 0, max_s;

ll cal(int i, ll s1, ll s2, ll s3) {

}

void sub3() {
}

void sub4() {
    int j = 1, k = 1;
    string ans;
    for(int i = n; i >= 1; i -= 3) {
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
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

//    freopen("DIVSEQ.inp","r",stdin);
//    freopen("DIVSEQ.out","w",stdout);

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        bool check_sub_4 = 1;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            sumarr += a[i];
            if(a[i] != i)
                check_sub_4 = 0;
        }
        if(check_sub_4)
            sub4();
        else
            sub3();
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
