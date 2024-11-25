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
        int u = inf.readInt(1, n);
        int v = inf.readInt(1, n);
        adj[u][v] = true;
    }

    int jury_ans = ans.readInt();
    int contestant_ans = ouf.readInt();

    if (contestant_ans != jury_ans) {
        quitf(_wa, "Wrong answer\nExpected: %d\nFound: %d", jury_ans, contestant_ans);
    }

    if (contestant_ans == -1) {
        quitf(_ok, "Correct answer: %d", contestant_ans);
    }

    if(contestant_ans == 0) {
        if(ouf.readInt(1, n) == 1 && ouf.readInt(1, n) == 1)
            quitf(_ok, "Correct answer: %d", contestant_ans);
    }

    int start1 = ouf.readInt(1, n);
    if (start1 != 1) {
        quitf(_wa, "Robot 1 must start from vertex 1, found: %d", start1);
    }

    int path_length1 = 0;
    int prev1 = start1;
    while (!ouf.seekEoln()) {
        int next = ouf.readInt(1, n);
        if (!adj[prev1][next]) {
            quitf(_wa, "No edge exists: %d->%d", prev1, next);
        }
        prev1 = next;
        path_length1++;
    }

    if (path_length1 != contestant_ans) {
        quitf(_wa, "Robot 1 path length mismatch. Expected: %d, Found: %d", 
              contestant_ans, path_length1);
    }


    int start2 = ouf.readInt(1, n);
    if (start2 != n) {
        quitf(_wa, "Robot 2 must start from vertex %d, found: %d", n, start2);
    }

    int path_length2 = 0;
    int prev2 = start2;
    while (!ouf.seekEoln()) {
        int next = ouf.readInt(1, n);
        if (!adj[prev2][next]) {
            quitf(_wa, "No edge exists: %d->%d", prev2, next);
        }
        prev2 = next;
        path_length2++;
    }

    // if (path_length2 != contestant_ans) {
    //     quitf(_wa, "Robot 2 path length mismatch. Expected: %d, Found: %d", 
    //           contestant_ans, path_length2);
    // }

    if(prev1 != prev2) {
        quitf(_wa, "Both robots must end at the same vertex, found: %d and %d", prev1, prev2);
    }

    if(path_length1 != contestant_ans) {
        quitf(_wa, "Path length mismatch. Expected: %d, Found: %d", contestant_ans, path_length1);    
    }

    // If we got here, everything is correct
    quitf(_ok, "Correct");
    
    return 0;
}