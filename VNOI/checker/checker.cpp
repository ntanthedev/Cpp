#include "testlib.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

struct Edge {
    int u, v;
    long long w; 

    int id;
};

int main(int argc, char* argv[]) {

    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int m = inf.readInt();

    vector<long long> d(n + 1);
    for (int i = 1; i <= n; ++i) {
        d[i] = inf.readLong();
    }

    vector<Edge> edges(m + 1);
    for (int i = 1; i <= m; ++i) {
        edges[i].u = inf.readInt();
        edges[i].v = inf.readInt();
        edges[i].w = abs(d[edges[i].u] - d[edges[i].v]);
        edges[i].id = i;
    }

    long long jury_min_max = ans.readLong(); 

    long long user_min_max = ouf.readLong(); 

    if (jury_min_max != user_min_max) {
        quitf(_wa, "Ket qua sai lech: Jury = %lld, User = %lld", jury_min_max, user_min_max);
    }

    if (ouf.seekEof()) {
        quitp(0.1, "Dung do lech (10%% diem), nhung khong in ra duong di.");
    }

    int current_node = 1;
    long long path_max_diff = 0;
    int edges_count = 0;

    while (!ouf.seekEof()) {
        int edge_id = ouf.readInt();
        edges_count++;

        if (edge_id < 1 || edge_id > m) {
            quitp(0.1, "Dung do lech (10%% diem), nhung chi so canh khong hop le: %d", edge_id);
        }

        int u = edges[edge_id].u;
        int v = edges[edge_id].v;
        long long w = edges[edge_id].w;

        if (u != current_node && v != current_node) {
            quitp(0.1, "Dung do lech (10%% diem), nhung duong di bi dut quang. Canh %d (%d-%d) khong noi voi dinh %d", 
                  edge_id, u, v, current_node);
        }

        current_node = (u == current_node) ? v : u;

        path_max_diff = max(path_max_diff, w);
    }

    if (current_node != n) {
        quitp(0.1, "Dung do lech (10%% diem), nhung duong di khong ket thuc tai N (ket thuc tai %d).", current_node);
    }

    if (path_max_diff != user_min_max) {
        quitp(0.1, "Dung do lech (10%% diem), nhung duong di in ra co do lech thuc te (%lld) khac voi gia tri da in (%lld).", 
              path_max_diff, user_min_max);
    }

    quitf(_ok, "Chinh xac hoan toan! MaxDiff = %lld, Do dai = %d canh.", user_min_max, edges_count);
}