#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int a[1000099],h[1000099];
int n;
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int m = inf.readInt();
    int n = inf.readInt();

    vector<string> a(m + 2);
    for (int i = 0; i < m + 2; ++i) {
        a[i] = string(n + 2, '#');
    }

    int sx = -1, sy = -1;
    for (int i = 1; i <= m; ++i) {
        a[i] = "#" + inf.readToken() + "#"; // Đọc từng dòng và thêm "#" ở đầu và cuối
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == '*') {
                sx = i;
                sy = j;
            }
        }
    }

    if (sx == -1) {
        quitf(_fail, "Không tìm thấy vị trí bắt đầu");
    }

    if(ans.eof()) {
        if(ouf.eof())
            quitf(_ok, "Ket qua dung");
        else 
            quitf(_wa, "Ket qua sai");
    }
    else 
        if(ouf.eof()) 
            quitf(_wa, "ket qua sai");

    string path = ouf.readToken();
    

    int x = sx, y = sy;
    for (char c : path) {
        if (c == 'N') x--;
        else if (c == 'S') x++;
        else if (c == 'W') y--;
        else if (c == 'E') y++;
        else quitf(_wa, "Output ký tự không hợp lệ: \"%c\"", c);

        if (a[x][y] == '#') {
            quitf(_wa, "Di vào ô cấm (%d, %d)", x, y);
        }
    }

    if (x != 1 && x != m && y != 1 && y != n) {
        quitf(_wa, "Không đi được ra biên");
    }

    quitf(_ok, "Correct!");
    return 0;
}