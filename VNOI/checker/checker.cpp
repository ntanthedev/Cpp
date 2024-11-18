#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1009;

int a[MAXN + 2][MAXN + 2];
int n, m, x, y;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    n = inf.readInt();
    m = inf.readInt();
    x = inf.readInt();
    y = inf.readInt();

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = inf.readInt();
        }
    }

    for (int i = 0; i <= n + 1; ++i) {
        a[0][i] = 2;
        a[m + 1][i] = 2;
    }
    for (int i = 0; i <= m + 1; ++i) {
        a[i][0] = 2;
        a[i][n + 1] = 2;
    }

    long long res = ouf.readLong();
    long long reshs = ans.readLong();

    if (res != 0) {
        if (reshs != 0) {
            int loi = 0;
            int reshsSb = 1;
            bool flag = inf.eof();

            ans.skipBlanks();
            if (ans.seekEof()) return 0;

            while (!ans.seekEof()) {
                int u = ans.readInt();
                int v = ans.readInt();
                reshsSb++;

                if (a[u][v] == 1) {
                    loi = 1;
                    quitf(_wa, "Di chuyen den o (%d,%d) co cam bay", x, y);
                    return 0;
                }

                if (((x == u) && (y == v - 1)) ||
                    ((x == u) && (y == v + 1)) ||
                    ((y == v) && (x == u - 1)) ||
                    ((y == v) && (x == u + 1))) {
                    x = u;
                    y = v;
                } else {
                    loi = 2;
                    quitf(_wa, "Duong di khong phu hop\nO (%d %d) khong the den (%d %d)", x, y, u, v);
                    return 0;
                }
            }

            if (loi != 0) {
                quitf(_wa, "Ket qua 'Sai'\n0.0");
            } else if (x == 1 || y == 1 || x == m || y == n) {
                if (reshsSb != reshs) {
                    quitf(_fail, "Tien Hau Bat Nhat\nSo buoc thong bao: %lld. So buoc truy vet: %d\n0.5", reshs, reshsSb);
                } else {
                    if (res == reshs) {
                        quitf(_ok, "Ket qua dung\n1.0");
                    }
                    if (res > reshs && loi == 0 && reshsSb == reshs) {
                        quitf(_ok, "Ket qua \"Toi Uu\" hon dap an\n1.5");
                    }
                    if (res < reshs) {
                        quitf(_wa, "Ket qua chua toi uu\nDap an: %lld\nTra loi: %lld\n0.5", res, reshs);
                    }
                }
            } else {
                quitf(_wa, "Nha tham hiem chua ra khoi me cung\n0.0");
            }
        } else {
            quitf(_wa, "Ket qua 'Sai'\nDap an: Me cung co duong di\nTra loi: Khong co duong di\n0.0");
        }
    } else {
        if (reshs == 0) {
            quitf(_ok, "Ket qua dung\n1.0");
        } else {
            quitf(_wa, "Ket qua 'Sai'\n0.0");
        }
    }

    return 0;
}