Mình kiểm lại sample trước khi viết pack: **đáp án đúng là `11`**, không phải `14`.

Một phương án tối ưu là:

* Giai đoạn 1: tháng ~3~ → tổng ~4~
* Giai đoạn 2: tháng ~4..6~ → tổng ~2 + (-1) + 6 = 7~
* Tổng = ~11~

Dưới đây là pack hoàn chỉnh gồm **statement chuẩn VNOJ** + **generator C++17 dùng `testlib.h`**, sinh đầy đủ `.inp` và `.out`.

---

## Statement VNOJ (Markdown, có đọc/ghi file)

````md
# Kế Hoạch Đầu Tư Kép

Công ty của bạn theo dõi lợi nhuận dự kiến trong ~N~ tháng tới, tháng thứ ~i~ có lợi nhuận là ~A_i~ (có thể âm).

Bạn được yêu cầu chọn ra **đúng 2 giai đoạn** đầu tư. Mỗi giai đoạn là một đoạn gồm các tháng liên tiếp.

- Giai đoạn 1 phải có độ dài nằm trong đoạn ~[L_1, R_1]~.
- Giai đoạn 2 phải có độ dài nằm trong đoạn ~[L_2, R_2]~.
- Giai đoạn 1 phải kết thúc **trước khi** Giai đoạn 2 bắt đầu, tức là hai giai đoạn **không được giao nhau**.

Hãy chọn 2 giai đoạn sao cho **tổng lợi nhuận của cả 2 giai đoạn là lớn nhất**.

Dữ liệu đảm bảo luôn tồn tại ít nhất một cách chọn hợp lệ.

## Input

Dữ liệu được đọc từ file ~INVEST.INP~:

- Dòng 1 chứa số nguyên ~N~.
- Dòng 2 chứa bốn số nguyên ~L_1, R_1, L_2, R_2~.
- Dòng 3 chứa ~N~ số nguyên ~A_1, A_2, \dots, A_N~.

## Output

Ghi ra file ~INVEST.OUT~:

- Một số nguyên duy nhất là tổng lợi nhuận lớn nhất của đúng 2 giai đoạn đầu tư.

## Constraints

- ~1 \le N \le 10^5~
- ~1 \le L_k \le R_k \le N~
- ~|A_i| \le 10^9~

Dữ liệu đảm bảo luôn tồn tại cách chọn hợp lệ.

Đáp án luôn nằm trong kiểu số nguyên có dấu 64-bit.

## Sample Input

```txt
7
1 2 2 3
3 -5 4 2 -1 6 -2
````

## Sample Output

```txt
11
```

## Subtasks

* ~30%~ số test: ~N \le 500~
* ~30%~ số test: ~L_1 = R_1 = 1~ và ~L_2 = R_2 = 1~
* ~40%~ số test: không có ràng buộc gì thêm

## Note

Một phương án tối ưu là:

* Giai đoạn 1: tháng ~3~
  Tổng lợi nhuận: ~4~
* Giai đoạn 2: từ tháng ~4~ đến tháng ~6~
  Tổng lợi nhuận: ~2 + (-1) + 6 = 7~

Tổng lợi nhuận đạt được là ~4 + 7 = 11~.

Lưu ý rằng hai giai đoạn chỉ cần **không giao nhau**, nên chúng có thể đứng sát nhau. Trong ví dụ trên, giai đoạn 1 kết thúc ở tháng ~3~ và giai đoạn 2 bắt đầu ngay ở tháng ~4~ là hợp lệ.

````

---

## Generator C++17 dùng `testlib.h` (sinh cả `.inp` và `.out`)

Tên file gợi ý: `gen_invest.cpp`

```cpp
#include <bits/stdc++.h>
#include <filesystem>
#include "testlib.h"

using namespace std;
namespace fs = std::filesystem;

using ll = long long;
static const ll NEG_INF = -(1LL << 60);

struct TestCase {
    string tag;
    int N = 0;
    int L1 = 0, R1 = 0, L2 = 0, R2 = 0;
    vector<ll> A; // 0-indexed
};

static ll rndLL(ll l, ll r) {
    return rnd.next(l, r);
}

static TestCase makeTC(
    const string& tag,
    int N, int L1, int R1, int L2, int R2,
    const vector<ll>& A
) {
    TestCase tc;
    tc.tag = tag;
    tc.N = N;
    tc.L1 = L1;
    tc.R1 = R1;
    tc.L2 = L2;
    tc.R2 = R2;
    tc.A = A;
    return tc;
}

static void validateTC(const TestCase& tc) {
    assert(1 <= tc.N && tc.N <= 100000);
    assert(1 <= tc.L1 && tc.L1 <= tc.R1 && tc.R1 <= tc.N);
    assert(1 <= tc.L2 && tc.L2 <= tc.R2 && tc.R2 <= tc.N);
    assert(tc.L1 + tc.L2 <= tc.N); // sufficient for existence
    assert((int)tc.A.size() == tc.N);
    for (ll x : tc.A) {
        assert(-1000000000LL <= x && x <= 1000000000LL);
    }
}

// Best sum of ONE segment with length in [L, R], ending at or before i.
static vector<ll> bestPrefixOne(const vector<ll>& arr1, int L, int R) {
    int n = (int)arr1.size() - 1; // arr1 is 1-indexed
    vector<ll> pref(n + 1, 0), best(n + 1, NEG_INF);

    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + arr1[i];

    deque<int> dq; // indices k of pref[k], increasing by pref value

    for (int i = 1; i <= n; ++i) {
        int addIdx = i - L;
        if (addIdx >= 0) {
            while (!dq.empty() && pref[dq.back()] >= pref[addIdx]) dq.pop_back();
            dq.push_back(addIdx);
        }

        while (!dq.empty() && dq.front() < i - R) dq.pop_front();

        ll exact = NEG_INF;
        if (!dq.empty()) {
            exact = pref[i] - pref[dq.front()];
        }

        best[i] = max(best[i - 1], exact);
    }

    return best;
}

// O(N) solver using prefix/suffix decomposition + deque
static ll solveFast(const TestCase& tc) {
    int n = tc.N;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) a[i] = tc.A[i - 1];

    vector<ll> leftBest = bestPrefixOne(a, tc.L1, tc.R1);

    vector<ll> rev(n + 1);
    for (int i = 1; i <= n; ++i) rev[i] = a[n - i + 1];

    vector<ll> revBest = bestPrefixOne(rev, tc.L2, tc.R2);

    vector<ll> rightBest(n + 2, NEG_INF);
    for (int i = 1; i <= n; ++i) {
        rightBest[i] = revBest[n - i + 1];
    }

    ll ans = NEG_INF;
    for (int split = 1; split < n; ++split) {
        if (leftBest[split] == NEG_INF || rightBest[split + 1] == NEG_INF) continue;
        ans = max(ans, leftBest[split] + rightBest[split + 1]);
    }

    return ans;
}

// Brute for small tests only
static ll solveBrute(const TestCase& tc) {
    int n = tc.N;
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + tc.A[i - 1];

    ll ans = NEG_INF;

    for (int l1 = 1; l1 <= n; ++l1) {
        for (int r1 = l1; r1 <= n; ++r1) {
            int len1 = r1 - l1 + 1;
            if (!(tc.L1 <= len1 && len1 <= tc.R1)) continue;
            ll s1 = pref[r1] - pref[l1 - 1];

            for (int l2 = r1 + 1; l2 <= n; ++l2) {
                for (int r2 = l2; r2 <= n; ++r2) {
                    int len2 = r2 - l2 + 1;
                    if (!(tc.L2 <= len2 && len2 <= tc.R2)) continue;
                    ll s2 = pref[r2] - pref[l2 - 1];
                    ans = max(ans, s1 + s2);
                }
            }
        }
    }

    return ans;
}

static string id3(int x) {
    stringstream ss;
    ss << setw(3) << setfill('0') << x;
    return ss.str();
}

static void writeInputFile(const TestCase& tc, const fs::path& path) {
    ofstream fout(path);
    fout << tc.N << '\n';
    fout << tc.L1 << ' ' << tc.R1 << ' ' << tc.L2 << ' ' << tc.R2 << '\n';
    for (int i = 0; i < tc.N; ++i) {
        if (i) fout << ' ';
        fout << tc.A[i];
    }
    fout << '\n';
}

static void writeOutputFile(ll ans, const fs::path& path) {
    ofstream fout(path);
    fout << ans << '\n';
}

static void genFeasibleLens(int n, int& L1, int& R1, int& L2, int& R2) {
    L1 = rnd.next(1, n - 1);
    L2 = rnd.next(1, n - L1);
    R1 = rnd.next(L1, n - L2);
    R2 = rnd.next(L2, n - L1);
}

// ------------------------
// Small / medium generators
// ------------------------

static TestCase genRandomSmallUniform(const string& tag, int n) {
    int L1, R1, L2, R2;
    genFeasibleLens(n, L1, R1, L2, R2);

    vector<ll> A(n);
    for (int i = 0; i < n; ++i) A[i] = rndLL(-20, 20);

    return makeTC(tag, n, L1, R1, L2, R2, A);
}

static TestCase genRandomSmallNegHeavy(const string& tag, int n) {
    int L1, R1, L2, R2;
    genFeasibleLens(n, L1, R1, L2, R2);

    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        int t = rnd.next(0, 99);
        if (t < 70) A[i] = -rndLL(0, 25);
        else A[i] = rndLL(-5, 15);
    }

    return makeTC(tag, n, L1, R1, L2, R2, A);
}

static TestCase genSmallSinglesOnly(const string& tag, int n) {
    int L1 = 1, R1 = 1, L2 = 1, R2 = 1;

    vector<ll> A(n);
    for (int i = 0; i < n; ++i) A[i] = rndLL(-50, 50);

    return makeTC(tag, n, L1, R1, L2, R2, A);
}

static TestCase genSmallFixedLens(const string& tag, int n) {
    int L1 = rnd.next(1, min(5, n - 1));
    int L2 = rnd.next(1, min(5, n - L1));
    int R1 = L1;
    int R2 = L2;

    vector<ll> A(n);
    for (int i = 0; i < n; ++i) A[i] = rndLL(-30, 30);

    return makeTC(tag, n, L1, R1, L2, R2, A);
}

// Blocks of positives / negatives to stress split logic
static TestCase genBlocksMedium(const string& tag, int n) {
    int L1 = rnd.next(5, min(80, n - 1));
    int L2 = rnd.next(5, min(80, n - L1));
    int R1 = rnd.next(L1, min(n - L2, L1 + 80));
    int R2 = rnd.next(L2, min(n - L1, L2 + 80));

    vector<ll> A;
    A.reserve(n);

    while ((int)A.size() < n) {
        int len = rnd.next(10, 70);
        bool positive = rnd.next(0, 99) < 45;
        ll base = positive ? rndLL(20, 150) : -rndLL(20, 150);

        for (int i = 0; i < len && (int)A.size() < n; ++i) {
            A.push_back(base + rndLL(-10, 10));
        }
    }

    return makeTC(tag, n, L1, R1, L2, R2, A);
}

// Sparse spikes on a mostly negative background
static TestCase genSpikesMedium(const string& tag, int n) {
    int L1 = rnd.next(1, min(50, n - 1));
    int L2 = rnd.next(1, min(50, n - L1));
    int R1 = rnd.next(L1, min(n - L2, L1 + 60));
    int R2 = rnd.next(L2, min(n - L1, L2 + 60));

    vector<ll> A(n, -rndLL(5, 20));

    for (int t = 0; t < n / 20; ++t) {
        int pos = rnd.next(0, n - 1);
        int len = rnd.next(1, 20);
        ll val = rndLL(50, 300);
        for (int i = pos; i < min(n, pos + len); ++i) {
            A[i] = val + rndLL(-20, 20);
        }
    }

    return makeTC(tag, n, L1, R1, L2, R2, A);
}

static TestCase genSinglesLarge(const string& tag, int n) {
    int L1 = 1, R1 = 1, L2 = 1, R2 = 1;

    vector<ll> A(n);
    for (int i = 0; i < n; ++i) A[i] = rndLL(-1000000, 1000000);

    return makeTC(tag, n, L1, R1, L2, R2, A);
}

static TestCase genExtremeRandom(const string& tag, int n) {
    int L1, R1, L2, R2;
    genFeasibleLens(n, L1, R1, L2, R2);

    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        int t = rnd.next(0, 99);
        if (t < 40) A[i] = -1000000000LL;
        else if (t < 80) A[i] = 1000000000LL;
        else A[i] = rndLL(-1000, 1000);
    }

    return makeTC(tag, n, L1, R1, L2, R2, A);
}

// ------------------------
// Add helpers
// ------------------------

static void addFixed(
    vector<TestCase>& tests,
    const string& tag,
    int N, int L1, int R1, int L2, int R2,
    const vector<ll>& A,
    ll expected
) {
    TestCase tc = makeTC(tag, N, L1, R1, L2, R2, A);
    validateTC(tc);

    ll fast = solveFast(tc);
    if (fast != expected) {
        cerr << "Mismatch in " << tag
             << ": fast=" << fast
             << ", expected=" << expected << '\n';
        assert(false);
    }

    if (N <= 60) {
        ll brute = solveBrute(tc);
        if (brute != expected) {
            cerr << "Brute mismatch in " << tag
                 << ": brute=" << brute
                 << ", expected=" << expected << '\n';
            assert(false);
        }
    }

    tests.push_back(tc);
}

static void addChecked(vector<TestCase>& tests, const TestCase& tc) {
    validateTC(tc);
    ll fast = solveFast(tc);

    if (tc.N <= 60) {
        ll brute = solveBrute(tc);
        if (fast != brute) {
            cerr << "Checked mismatch in " << tc.tag
                 << ": fast=" << fast
                 << ", brute=" << brute << '\n';
            assert(false);
        }
    }

    tests.push_back(tc);
}

static void addUnchecked(vector<TestCase>& tests, const TestCase& tc) {
    validateTC(tc);
    tests.push_back(tc);
}

// ------------------------
// Planned base set: 24 tests
// ------------------------

static vector<TestCase> buildBasePlan() {
    vector<TestCase> tests;

    // A. Sample / Debug (4)
    addFixed(tests, "A1_sample_corrected",
             7, 1, 2, 2, 3,
             {3, -5, 4, 2, -1, 6, -2},
             11);

    addFixed(tests, "A2_min_feasible",
             2, 1, 1, 1, 1,
             {5, 7},
             12);

    addFixed(tests, "A3_all_negative_exactly_two",
             4, 1, 1, 1, 1,
             {-5, -2, -7, -1},
             -3);

    addFixed(tests, "A4_touching_is_allowed",
             3, 1, 1, 2, 2,
             {5, 5, 5},
             15);

    // B. Small brute-checkable (6)
    addChecked(tests, genRandomSmallUniform("B1_small_uniform_1", rnd.next(15, 35)));
    addChecked(tests, genRandomSmallUniform("B2_small_uniform_2", rnd.next(15, 35)));
    addChecked(tests, genRandomSmallNegHeavy("B3_small_neg_heavy", rnd.next(15, 35)));
    addChecked(tests, genSmallSinglesOnly("B4_small_singles_only", rnd.next(15, 35)));
    addChecked(tests, genSmallFixedLens("B5_small_fixed_lens", rnd.next(15, 35)));
    addChecked(tests, genRandomSmallUniform("B6_small_uniform_3", rnd.next(15, 35)));

    // C. Edge-crafted / handmade (6)
    addFixed(tests, "C1_overlap_trap",
             4, 2, 2, 2, 2,
             {10, 10, 10, 1},
             31);

    addFixed(tests, "C2_exact_R1_and_L2",
             5, 1, 2, 2, 2,
             {5, 5, 5, 5, 5},
             20);

    addFixed(tests, "C3_forced_bad_second_segment",
             4, 1, 1, 2, 2,
             {100, -100, -100, -100},
             -100);

    addFixed(tests, "C4_touching_long_segments",
             6, 2, 2, 3, 3,
             {5, 5, 4, 4, 4, 1},
             22);

    addFixed(tests, "C5_overflow_values",
             5, 1, 2, 1, 2,
             {1000000000LL, -1000000000LL, 1000000000LL, -1000000000LL, 1000000000LL},
             2000000000LL);

    addFixed(tests, "C6_all_negative_longer_segments",
             5, 2, 2, 2, 2,
             {-1, -2, -3, -4, -5},
             -10);

    // D. Controlled random (4)
    addUnchecked(tests, genBlocksMedium("D1_blocks_medium", rnd.next(2500, 4000)));
    addUnchecked(tests, genSpikesMedium("D2_spikes_medium", rnd.next(2500, 4000)));
    addUnchecked(tests, genSinglesLarge("D3_singles_large", rnd.next(3000, 6000)));
    addUnchecked(tests, genExtremeRandom("D4_extreme_random", rnd.next(2500, 5000)));

    // E. Max / Stress (4)
    {
        int n = 100000;
        vector<ll> A(n, 1000000000LL);
        addUnchecked(tests, makeTC("E1_all_equal_positive_max", n, 1, 1, 1, 1, A));
    }

    {
        int n = 100000;
        vector<ll> A(n, -1000000000LL);
        addUnchecked(tests, makeTC("E2_all_negative_singletons", n, 1, 1, 1, 1, A));
    }

    {
        int n = 100000;
        int L1 = 100, R1 = 1000, L2 = 200, R2 = 1200;
        vector<ll> A;
        A.reserve(n);
        while ((int)A.size() < n) {
            int len = rnd.next(50, 300);
            bool positive = rnd.next(0, 99) < 50;
            ll base = positive ? rndLL(1000, 5000) : -rndLL(1000, 5000);
            for (int i = 0; i < len && (int)A.size() < n; ++i) {
                A.push_back(base + rndLL(-200, 200));
            }
        }
        addUnchecked(tests, makeTC("E3_long_blocks_max", n, L1, R1, L2, R2, A));
    }

    {
        int n = 100000;
        int L1 = 1, R1 = 50000, L2 = 1, R2 = 50000;
        vector<ll> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = (i % 2 == 0 ? 1000000000LL : -1000000000LL);
        }
        addUnchecked(tests, makeTC("E4_alternating_extreme", n, L1, R1, L2, R2, A));
    }

    assert((int)tests.size() == 24);
    return tests;
}

static TestCase genExtraControlled(const string& tag, int id) {
    int type = id % 4;
    if (type == 0) return genBlocksMedium(tag, rnd.next(2000, 6000));
    if (type == 1) return genSpikesMedium(tag, rnd.next(2000, 6000));
    if (type == 2) return genSinglesLarge(tag, rnd.next(2000, 6000));
    return genExtremeRandom(tag, rnd.next(2000, 6000));
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " N seed_key out_dir [emit_out]\n";
        cerr << "Example: " << argv[0] << " 24 seed42 tests 1\n";
        return 1;
    }

    int wantN = stoi(argv[1]);
    string seedKey = argv[2];
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
            TestCase tc = genExtraControlled("X_extra_" + to_string(extraId), extraId);
            addUnchecked(tests, tc);
            ++extraId;
        }
    }

    int cntA = 0, cntB = 0, cntC = 0, cntD = 0, cntE = 0, cntX = 0;

    for (int i = 0; i < (int)tests.size(); ++i) {
        const TestCase& tc = tests[i];
        validateTC(tc);

        ll ans = solveFast(tc);
        if (tc.N <= 60) {
            ll brute = solveBrute(tc);
            if (ans != brute) {
                cerr << "Main verification mismatch in " << tc.tag
                     << ": fast=" << ans
                     << ", brute=" << brute << '\n';
                return 1;
            }
        }

        string stem = id3(i + 1);
        fs::path inPath = fs::path(outDir) / (stem + ".inp");
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
             << " L1=" << tc.L1
             << " R1=" << tc.R1
             << " L2=" << tc.L2
             << " R2=" << tc.R2
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
````

---

## Cách chạy trên laptop

Biên dịch:

```bash
g++ -std=c++17 -O2 -pipe -o gen_invest gen_invest.cpp
```

Sinh đúng bộ mặc định 24 test, kèm đầy đủ `.inp` và `.out`:

```bash
./gen_invest 24 seed42 tests 1
```

Chỉ sinh `.inp`:

```bash
./gen_invest 24 seed42 tests 0
```

Kết quả tạo ra:

```txt
tests/001.inp
tests/001.out
...
tests/024.inp
tests/024.out
```

---

## Ghi chú quan trọng

* Generator đã tích hợp sẵn:

  * **solver nhanh ~O(N)**
  * **brute solver** cho test nhỏ để tự kiểm chéo
* Sample gốc của đề đã được sửa từ `14` thành `11`.
* Bộ test có chủ đích bắt các lỗi hay gặp:

  * cho phép chọn **ít hơn 2 đoạn** dù đề yêu cầu đúng 2
  * hiểu sai rằng hai đoạn phải cách nhau ít nhất 1 tháng
  * dùng `F[i] + G[i]` gây overlap
  * sai biên độ dài
  * overflow `int`

Nếu bạn muốn, bước tiếp theo mình có thể viết luôn **code AC C++17** đọc từ `INVEST.INP` và ghi ra `INVEST.OUT`.
