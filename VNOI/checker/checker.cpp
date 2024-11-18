#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
typedef long long ll;

int n, m;
bool w[N][N];

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int ouf_ans = ouf.readInt();
    int ans_ans = ans.readInt();
    
    m = inf.readInt();
    n = inf.readInt();
    int a = inf.readInt(), b = inf.readInt();

    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) 
            w[i][j] = inf.readInt();

    if(ans_ans == 0) {
        if(ouf_ans != 0) {
            quitp(0.0, "Me cung khong co duong di nhung nha tham hien co duong di");
        }
        else {
            quitp(100.0, "Ket qua dung");
        }
    } 
    else {
        if(ouf_ans == 0) {
            quitp(0.0, "Ket qua sai");
        }
        else {
            bool ok = false;
            vector<pair<int, int>> res;
            for(int i = 1; i <= ouf_ans; i++) {
                int x = ouf.readInt(), y = ouf.readInt();
                if(w[x][y]) {
                    quitp(0.0, "Di chuyen den o (%d, %d) co cam bay", x, y);
                }
                res.push_back({x, y});
            }

            if(!ouf.seekEof()) {
                quitp(0.0, "File output con thua");
            }

            if(make_pair(a, b) != res[0]) {
                quitp(0.0, "Diem bat dau khong dung");
            }

            if(res.back().first != 1 && res.back().first != m && res.back().second != 1 && res.back().second != n) {
                quitp(0.0, "Nha tham hien chua thoat khoi me cung");
            }

            auto [x, y] = res.front();

            for(int i = 1; i < res.size(); i++) {
                if(abs(res[i].first - x) + abs(res[i].second - y) != 1) {
                    quitp(0.0, "Tu diem %lld, %lld khong the den diem %lld, %lld", x, y, res[i].first, res[i].second);
                }
                x = res[i].first;
                y = res[i].second;
            }

            if(ouf_ans < ans_ans) 
                quitp(150.0, "Output toi uu hon ket qua");
            else if(ouf_ans == ans_ans)
                quitp(100.0, "Ket qua dung");
            else 
                quitp(50.0, "Ket qua chua toi uu");
        }
    }

    return 0;
}