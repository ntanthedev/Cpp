#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;
int n, m;
bool adj[MAXN][MAXN];

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    // Read input
    n = inf.readInt();
    m = inf.readInt();
    for(int i = 0; i < m; i++) {
        int u = inf.readInt();
        int v = inf.readInt();
        adj[u][v] = true;
    }

    // Read answers
    int jury_ans = ans.readInt();
    int contestant_ans = ouf.readInt();

    if (contestant_ans != jury_ans) {
        quitf(_wa, "Wrong answer\nExpected: %d\nFound: %d", jury_ans, contestant_ans);
    }

    if (contestant_ans == -1) {
        quitf(_ok, "Correct answer: -1");
    }

    // Validate first robot path
    int start1 = ouf.readInt();
    if (start1 != 1) {
        quitf(_wa, "Robot 1 must start from vertex 1, found: %d", start1);
    }

    int path_length1 = 0;
    int prev = start1;
    while (!ouf.seekEof()) {
        int next = ouf.readInt();
        if (next == 0) {
            quitf(_wa, "Invalid vertex: 0");
        }
        if (!adj[prev][next]) {
            quitf(_wa, "No edge exists: %d->%d", prev, next);
        }
        prev = next;
        path_length1++;
    }

    if (path_length1 != contestant_ans) {
        quitf(_wa, "Robot 1 path length mismatch. Expected: %d, Found: %d", 
              contestant_ans, path_length1);
    }

    // Validate second robot path
    int start2 = ouf.readInt();
    if (start2 != n) {
        quitf(_wa, "Robot 2 must start from vertex %d, found: %d", n, start2);
    }

    int path_length2 = 0;
    prev = start2;
    while (!ouf.seekEof()) {
        int next = ouf.readInt();
        if (next == 0) {
            quitf(_wa, "Invalid vertex: 0");
        }
        if (!adj[prev][next]) {
            quitf(_wa, "No edge exists: %d->%d", prev, next);
        }
        prev = next;
        path_length2++;
    }

    if (path_length2 != contestant_ans) {
        quitf(_wa, "Robot 2 path length mismatch. Expected: %d, Found: %d", 
              contestant_ans, path_length2);
    }

    // If we got here, everything is correct
    quitf(_ok, "Correct");
    
    return 0;
}