#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int m = inf.readInt();

    vector<vector<int, int>> s(n + 1);
    map<int, bool> M;
    int cnt = 0;

    for(int i = 1, x, y; i <= m; i++) {
        x = inf.readInt();
        y = inf.readInt();
        s[y].push_back(x);
    }

    if (ans.readToken() == "IMPOSSIBLE") {
        if (ouf.readToken() == "IMPOSSIBLE") {
            quitf(_ok, "Correct: No solution exists");
        } else {
            quitf(_wa, "Wrong answer: Solution exists, but participant claims impossible");
        }
    }

    for(int i = 1, x; i <= n; i++) {
        x = ouf.readInt();
        if(M[x]) {
            quitf(_wa, "So xuat hien nhieu hon 1 lan");
        }
        for(auto y : s[x]) {
            if(!m[y])
                quitf(_wa, "");
        }
    }
}