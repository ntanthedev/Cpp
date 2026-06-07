#include <bits/stdc++.h>
#include <filesystem>
#include "testlib.h"

using namespace std;
namespace fs = std::filesystem;

using ll = long long;
static const ll NEG_INF = -(1LL << 60);

struct TestCase {
    string tag;
    int N = 0, L = 0, R = 0, D = 0;
    ll C = 0;
    vector<ll> P;
};

static TestCase makeTC(
    const string& tag,
    int N, int L, int R, ll C, int D,
    const vector<ll>& P
) {
    TestCase tc;
    tc.tag = tag;
    tc.N = N;
    tc.L = L;
    tc.R = R;
    tc.C = C;
    tc.D = D;
    tc.P = P;
    return tc;
}

static void validateTC(const TestCase& tc) {
    assert(1 <= tc.L && tc.L <= tc.R && tc.R <= tc.N && tc.N <= 100000);
    assert(0 <= tc.C && tc.C <= 1000000000LL);
    assert(0 <= tc.D && tc.D <= tc.N);
    assert((int)tc.P.size() == tc.N);
    for (ll x : tc.P) {
        assert(-1000000000LL <= x && x <= 1000000000LL);
    }
}

// O(N) official/oracle-fast solver using DP + prefix sum + monotonic deque
static ll solveFast(const TestCase& tc) {
    int n = tc.N, L = tc.L, R = tc.R, D = tc.D;
    ll C = tc.C;

    vector<ll> S(n + 1, 0), F(n + 1, NEG_INF), best(n + 1, 0);
    for (int i = 1; i <= n; ++i) S[i] = S[i - 1] + tc.P[i - 1];

    deque<pair<int, ll>> dq; // (j, value = best[j-D] - S[j])

    for (int i = 1; i <= n; ++i) {
        int jAdd = i - L;
        if (jAdd >= 0) {
            int prevLim = jAdd - D;
            ll prevBest = (prevLim >= 0 ? best[prevLim] : 0LL);
            ll val = prevBest - S[jAdd];

            while (!dq.empty() && dq.back().second <= val) dq.pop_back();
            dq.push_back({jAdd, val});
        }

        while (!dq.empty() && dq.front().first < i - R) dq.pop_front();

        if (!dq.empty()) {
            F[i] = S[i] - C + dq.front().second;
        }

        best[i] = max(best[i - 1], F[i]);
    }

    return best[n];
}

// O(NR) brute/oracle for small tests only
static ll solveBrute(const TestCase& tc) {
    int n = tc.N, L = tc.L, R = tc.R, D = tc.D;
    ll C = tc.C;

    vector<ll> S(n + 1, 0), best(n + 1, 0);
    for (int i = 1; i <= n; ++i) S[i] = S[i - 1] + tc.P[i - 1];

    for (int i = 1; i <= n; ++i) {
        best[i] = best[i - 1]; // skip day i
        for (int len = L; len <= R && len <= i; ++len) {
            int j = i - len;         // current segment is [j+1 .. i]
            int prevLim = j - D;     // previous segment must end <= j-D
            ll prevBest = (prevLim >= 0 ? best[prevLim] : 0LL);
            ll gain = S[i] - S[j] - C;
            best[i] = max(best[i], prevBest + gain);
        }
    }

    return best[n];
}

static string id3(int x) {
    stringstream ss;
    ss << setw(3) << setfill('0') << x;
    return ss.str();
}

static void writeInputFile(const TestCase& tc, const fs::path& path) {
    ofstream fout(path);
    fout << tc.N << ' ' << tc.L << ' ' << tc.R << ' ' << tc.C << ' ' << tc.D << '\n';
    for (int i = 0; i < tc.N; ++i) {
        if (i) fout << ' ';
        fout << tc.P[i];
    }
    fout << '\n';
}

static void writeOutputFile(ll ans, const fs::path& path) {
    ofstream fout(path);
    fout << ans << '\n';
}

static ll rndLL(ll l, ll r) {
    return rnd.next(l, r);
}

// ------------------------
// Pattern generators
// ------------------------

static TestCase genRandomUniformSmall(const string& tag, int n, ll lo, ll hi) {
    int L = rnd.next(1, n);
    int R = rnd.next(L, n);
    int D = rnd.next(0, n);
    ll C = rndLL(0, 25);

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) P[i] = rndLL(lo, hi);

    return makeTC(tag, n, L, R, C, D, P);
}

static TestCase genRandomNegHeavySmall(const string& tag, int n) {
    int L = rnd.next(1, n);
    int R = rnd.next(L, n);
    int D = rnd.next(0, n);
    ll C = rndLL(0, 20);

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) {
        int t = rnd.next(0, 99);
        if (t < 75) P[i] = -rndLL(0, 20);
        else P[i] = rndLL(-5, 10);
    }

    return makeTC(tag, n, L, R, C, D, P);
}

static TestCase genRandomPosHeavySmallD0C0(const string& tag, int n) {
    int L = rnd.next(1, n);
    int R = rnd.next(L, n);
    int D = 0;
    ll C = 0;

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) {
        int t = rnd.next(0, 99);
        if (t < 70) P[i] = rndLL(1, 15);
        else P[i] = rndLL(-6, 6);
    }

    return makeTC(tag, n, L, R, C, D, P);
}

static TestCase genRandomFixedLRSmall(const string& tag, int n) {
    int L = rnd.next(1, n);
    int R = L;
    int D = rnd.next(0, n);
    ll C = rndLL(0, 25);

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) P[i] = rndLL(-10, 10);

    return makeTC(tag, n, L, R, C, D, P);
}

static TestCase genRandomHugeDSmall(const string& tag, int n) {
    int L = rnd.next(1, min(n, 6));
    int R = rnd.next(L, min(n, L + 5));
    int D = rnd.next(max(0, n - 3), n);
    ll C = rndLL(0, 20);

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) P[i] = rndLL(-10, 15);

    return makeTC(tag, n, L, R, C, D, P);
}

static TestCase genRandomMediumChecked(const string& tag, int n) {
    int L = rnd.next(1, n);
    int R = rnd.next(L, n);
    int D = rnd.next(0, n);
    ll C = rndLL(0, 50);

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) P[i] = rndLL(-30, 30);

    return makeTC(tag, n, L, R, C, D, P);
}

// D=0, C=0, nhiều block dương/âm để bắt code cấm ghép sát
static TestCase genBlocksD0C0(const string& tag, int n) {
    int L = rnd.next(1, min(n, 12));
    int R = rnd.next(L, min(n, L + 18));
    int D = 0;
    ll C = 0;

    vector<ll> P;
    P.reserve(n);

    while ((int)P.size() < n) {
        int len = rnd.next(1, 25);
        bool positive = rnd.next(0, 99) < 55;
        ll base = positive ? rndLL(3, 15) : -rndLL(1, 10);

        for (int k = 0; k < len && (int)P.size() < n; ++k) {
            ll x = base + rndLL(-2, 2);
            x = max(-1000000000LL, min(1000000000LL, x));
            P.push_back(x);
        }
    }

    return makeTC(tag, n, L, R, C, D, P);
}

// Positive islands separated by negative moats
static TestCase genIslands(const string& tag, int n) {
    int L = rnd.next(15, min(n, 40));
    int R = rnd.next(L, min(n, L + 25));
    int D = rnd.next(2, min(n, 12));
    ll C = rndLL(10, 80);

    vector<ll> P(n, 0);
    for (int i = 0; i < n; ++i) P[i] = -rndLL(3, 15);

    int pos = 0;
    while (pos < n) {
        pos += rnd.next(5, 20);
        if (pos >= n) break;

        int mode = rnd.next(0, 2);
        int len;
        if (mode == 0) len = max(1, L - 1);
        else if (mode == 1) len = L;
        else len = R;

        len += rnd.next(-2, 2);
        len = max(1, len);
        len = min(len, n - pos);

        for (int i = pos; i < pos + len; ++i) {
            P[i] = rndLL(8, 25);
        }
        pos += len;
    }

    return makeTC(tag, n, L, R, C, D, P);
}

// Long plateaus / repeated values to stress deque equality handling
static TestCase genPlateau(const string& tag, int n) {
    int L = rnd.next(10, min(n, 30));
    int R = rnd.next(L, min(n, L + 30));
    int D = rnd.next(0, min(n, 20));
    ll C = rndLL(0, 50);

    vector<ll> vals = {-3, -1, 0, 1, 3};
    vector<ll> P;
    P.reserve(n);

    while ((int)P.size() < n) {
        int len = rnd.next(20, 80);
        ll v = vals[rnd.next(0, (int)vals.size() - 1)];
        for (int i = 0; i < len && (int)P.size() < n; ++i) P.push_back(v);
    }

    return makeTC(tag, n, L, R, C, D, P);
}

// Extreme values to catch int overflow and INF mistakes
static TestCase genExtremeValue(const string& tag, int n) {
    int L = rnd.next(1, min(n, 500));
    int R = rnd.next(L, min(n, L + 500));
    int D = rnd.next(0, min(n, 500));
    ll C = rndLL(0, 1000000000LL);

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) {
        int t = rnd.next(0, 99);
        if (t < 40) P[i] = -1000000000LL;
        else if (t < 70) P[i] = 0;
        else P[i] = 1000000000LL;
    }

    return makeTC(tag, n, L, R, C, D, P);
}

// Very wide window: kills O(NR)
static TestCase genWideWindowStress(const string& tag, int n) {
    int L = 1;
    int R = n;
    int D = 0;
    ll C = rndLL(0, 1000000LL);

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) {
        P[i] = rndLL(-1000000LL, 1000000LL);
    }

    return makeTC(tag, n, L, R, C, D, P);
}

// Boundary churn for deque push/pop timing bugs
static TestCase genBoundaryChurn(const string& tag, int n) {
    int L = 350;
    int R = 700;
    int D = 2;
    ll C = 5000;

    vector<ll> P(n);
    for (int i = 0; i < n; ++i) {
        int t = i % 120;
        if (t < 40) P[i] = 1000 + (t % 5);
        else if (t < 80) P[i] = -950 - (t % 7);
        else P[i] = (t % 2 == 0 ? 20 : -20);
    }

    return makeTC(tag, n, L, R, C, D, P);
}

static TestCase genExtraControlledRandom(const string& tag, int id) {
    int type = id % 4;
    if (type == 0) return genBlocksD0C0(tag, rnd.next(1500, 5000));
    if (type == 1) return genIslands(tag, rnd.next(1500, 5000));
    if (type == 2) return genPlateau(tag, rnd.next(1500, 5000));
    return genExtremeValue(tag, rnd.next(1500, 5000));
}

// ------------------------
// Planned testset builder
// ------------------------

static void addFixed(vector<TestCase>& tests,
                     const string& tag,
                     int N, int L, int R, ll C, int D,
                     const vector<ll>& P,
                     ll expected) {
    TestCase tc = makeTC(tag, N, L, R, C, D, P);
    validateTC(tc);

    ll fast = solveFast(tc);
    assert(fast == expected);
    if (N <= 500) {
        ll brute = solveBrute(tc);
        assert(brute == expected);
    }

    tests.push_back(tc);
}

static void addChecked(vector<TestCase>& tests, const TestCase& tc) {
    validateTC(tc);
    ll fast = solveFast(tc);
    if (tc.N <= 500) {
        ll brute = solveBrute(tc);
        assert(fast == brute);
    }
    tests.push_back(tc);
}

static void addUnchecked(vector<TestCase>& tests, const TestCase& tc) {
    validateTC(tc);
    tests.push_back(tc);
}

static vector<TestCase> buildBasePlan() {
    vector<TestCase> tests;

    // ---------------- A: Sample / Debug (4) ----------------
    addFixed(tests, "A1_sample_corrected",
             8, 2, 3, 5, 1,
             {10, -2, 8, -1, 7, 5, -3, 10},
             18);

    addFixed(tests, "A2_min_positive",
             1, 1, 1, 0, 0,
             {5},
             5);

    addFixed(tests, "A3_min_negative",
             1, 1, 1, 0, 0,
             {-5},
             0);

    addFixed(tests, "A4_D0_adjacent_allowed",
             2, 1, 1, 0, 0,
             {1, 1},
             2);

    // ---------------- B: Small brute-checkable (6) ----------------
    addChecked(tests, genRandomUniformSmall("B1_small_uniform_1", rnd.next(12, 18), -7, 7));
    addChecked(tests, genRandomUniformSmall("B2_small_uniform_2", rnd.next(12, 18), -9, 9));
    addChecked(tests, genRandomNegHeavySmall("B3_small_neg_heavy", rnd.next(12, 18)));
    addChecked(tests, genRandomPosHeavySmallD0C0("B4_small_pos_heavy_D0C0", rnd.next(12, 18)));
    addChecked(tests, genRandomFixedLRSmall("B5_small_fixed_LR", rnd.next(12, 18)));
    addChecked(tests, genRandomHugeDSmall("B6_small_huge_D", rnd.next(12, 18)));

    // ---------------- C: Edge-crafted handmade (8) ----------------
    addFixed(tests, "C1_start_from_day1",
             3, 2, 2, 0, 0,
             {10, 10, -100},
             20);

    addFixed(tests, "C2_exact_R_boundary",
             3, 2, 3, 0, 0,
             {5, 5, 5},
             15);

    addFixed(tests, "C3_exact_L_boundary",
             2, 2, 2, 0, 0,
             {4, 4},
             8);

    addFixed(tests, "C4_fee_per_campaign",
             3, 1, 3, 5, 0,
             {6, 6, 6},
             13);

    addFixed(tests, "C5_exact_D_gap",
             4, 1, 1, 0, 2,
             {5, 0, 0, 5},
             10);

    addFixed(tests, "C6_large_D_only_one_campaign",
             6, 2, 3, 1, 6,
             {4, 4, -100, 5, 5, 5},
             14);

    addFixed(tests, "C7_F_vs_MaxF_bug",
             4, 2, 2, 0, 0,
             {-10, -10, -5, 10},
             5);

    addFixed(tests, "C8_skip_all_campaigns",
             5, 1, 3, 2, 0,
             {-1, -2, -3, -4, -5},
             0);

    // ---------------- D: Controlled random (6) ----------------
    addChecked(tests, genRandomMediumChecked("D1_medium_checked_1", rnd.next(220, 320)));
    addChecked(tests, genRandomMediumChecked("D2_medium_checked_2", rnd.next(330, 450)));

    addUnchecked(tests, genBlocksD0C0("D3_blocks_D0C0", rnd.next(2500, 4000)));
    addUnchecked(tests, genIslands("D4_positive_islands", rnd.next(2200, 3800)));
    addUnchecked(tests, genPlateau("D5_plateau_equal_values", rnd.next(2500, 4000)));
    addUnchecked(tests, genExtremeValue("D6_extreme_values", rnd.next(2500, 4000)));

    // ---------------- E: Max / Stress (4) ----------------
    {
        int n = 100000;
        vector<ll> P(n, 1000000000LL);
        addUnchecked(tests, makeTC("E1_overflow_killer", n, 1, 1, 0, 0, P));
    }

    {
        int n = 100000;
        vector<ll> P(n, -1000000000LL);
        addUnchecked(tests, makeTC("E2_all_negative_max", n, 1, n, 0, 0, P));
    }

    addUnchecked(tests, genWideWindowStress("E3_wide_window_stress", 100000));
    addUnchecked(tests, genBoundaryChurn("E4_boundary_churn", 100000));

    assert((int)tests.size() == 28);
    return tests;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " N seed_key out_dir [emit_out]\n";
        cerr << "Example: " << argv[0] << " 28 seed42 tests 1\n";
        return 1;
    }

    int wantN = stoi(argv[1]);
    string seedKey = argv[2]; // kept for CLI clarity; testlib already uses argv to seed rnd
    string outDir = argv[3];
    int emitOut = (argc >= 5 ? stoi(argv[4]) : 1);

    if (wantN <= 0) {
        cerr << "N must be positive.\n";
        return 1;
    }
    if (!(emitOut == 0 || emitOut == 1)) {
        cerr << "emit_out must be 0 or 1.\n";
        return 1;
    }

    fs::create_directories(outDir);

    vector<TestCase> tests = buildBasePlan();

    if ((int)tests.size() > wantN) {
        tests.resize(wantN);
    } else {
        int extraId = 1;
        while ((int)tests.size() < wantN) {
            TestCase tc = genExtraControlledRandom(
                "X_extra_controlled_" + to_string(extraId),
                extraId
            );
            addUnchecked(tests, tc);
            ++extraId;
        }
    }

    int cntA = 0, cntB = 0, cntC = 0, cntD = 0, cntE = 0, cntX = 0;

    for (int i = 0; i < (int)tests.size(); ++i) {
        const TestCase& tc = tests[i];
        validateTC(tc);

        ll ans = solveFast(tc);
        if (tc.N <= 500) {
            ll brute = solveBrute(tc);
            assert(ans == brute);
        }

        string stem = id3(i + 1);
        fs::path inPath = fs::path(outDir) / (stem + ".in");
        fs::path outPath = fs::path(outDir) / (stem + ".out");

        writeInputFile(tc, inPath);
        if (emitOut) writeOutputFile(ans, outPath);

        char g = tc.tag.empty() ? 'X' : tc.tag[0];
        if (g == 'A') ++cntA;
        else if (g == 'B') ++cntB;
        else if (g == 'C') ++cntC;
        else if (g == 'D') ++cntD;
        else if (g == 'E') ++cntE;
        else ++cntX;

        cerr << "[" << stem << "] "
             << tc.tag
             << " | N=" << tc.N
             << " L=" << tc.L
             << " R=" << tc.R
             << " C=" << tc.C
             << " D=" << tc.D
             << " | ans=" << ans
             << '\n';
    }

    cerr << "\nSeed key: " << seedKey << '\n';
    cerr << "Generated " << tests.size() << " test(s) into: " << outDir << '\n';
    cerr << "Group counts => "
         << "A=" << cntA << ", "
         << "B=" << cntB << ", "
         << "C=" << cntC << ", "
         << "D=" << cntD << ", "
         << "E=" << cntE << ", "
         << "X=" << cntX << '\n';

    return 0;
}