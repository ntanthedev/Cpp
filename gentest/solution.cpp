#include "testlib.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <filesystem>

using namespace std;

const long long INF = 4e18; // 4*10^18 an toàn cho long long, không bị tràn khi trừ
const int MOD = 1e9 + 7;

// Thuật toán nội bộ O(N*K) để sinh đáp án cực nhanh
pair<long long, int> solve(int n, int k, const vector<long long>& a, const vector<long long>& w) {
    vector<long long> f_prev(n + 1, 0);
    vector<int> c_prev(n + 1, 1);
    
    // Khởi tạo hàng 0
    f_prev[0] = 0; c_prev[0] = 1;
    for (int j = 1; j <= n; ++j) {
        f_prev[j] = 0; c_prev[j] = 1;
    }
    
    vector<long long> f_curr(n + 1);
    vector<int> c_curr(n + 1);

    for (int i = 1; i <= k; ++i) {
        fill(f_curr.begin(), f_curr.end(), -INF);
        fill(c_curr.begin(), c_curr.end(), 0);
        
        for (int j = i; j <= n; ++j) {
            long long val1 = -INF;
            if (f_prev[j - 1] != -INF) {
                val1 = f_prev[j - 1] + w[i - 1] * a[j - 1];
            }
            long long val2 = f_curr[j - 1];
            
            if (val1 == -INF && val2 == -INF) {
                f_curr[j] = -INF;
                c_curr[j] = 0;
            } else if (val1 > val2) {
                f_curr[j] = val1;
                c_curr[j] = c_prev[j - 1];
            } else if (val1 < val2) {
                f_curr[j] = val2;
                c_curr[j] = c_curr[j - 1];
            } else {
                f_curr[j] = val1;
                c_curr[j] = c_prev[j - 1] + c_curr[j - 1];
                if (c_curr[j] >= MOD) c_curr[j] -= MOD;
            }
        }
        f_prev = f_curr;
        c_prev = c_curr;
    }
    
    return {f_prev[n], c_prev[n]};
}

void gen_test(int test_id, int subtask) {
    string test_name = "tests/" + (test_id < 10 ? "0" : "") + to_string(test_id);
    ofstream fin(test_name + ".in");
    ofstream fout(test_name + ".out");

    int n, k;
    if (subtask == 1) {
        n = rnd.next(50, 100);
        k = 1;
        if (test_id <= 3) n = 100;
    } else if (subtask == 2) {
        n = rnd.next(500, 1000);
        k = rnd.next(2, 100);
        if (test_id == 11) { n = 5; k = 3; }
        if (test_id == 15 || test_id == 16) { n = 100; k = 100; }
    } else {
        n = rnd.next(90000, 100000);
        k = rnd.next(50, 100);
        if (test_id == 34) { n = 100; k = 100; }
    }

    vector<long long> a(n), w(k);
    
    if (test_id == 11) {
        a = {2, 8, 6, 3, 3}; w = {5, 2, 6}; // Ví dụ
    } else if (test_id == 1 || test_id == 12 || test_id == 32) {
        for(int i = 0; i < n; i++) a[i] = 0;
        for(int i = 0; i < k; i++) w[i] = rnd.next(-1000000LL, 1000000LL);
    } else if (test_id == 33) {
        for(int i = 0; i < n; i++) a[i] = rnd.next(-1000000000LL, 1000000000LL);
        for(int i = 0; i < k; i++) w[i] = 0;
    } else if (test_id == 2 || test_id == 13 || test_id == 31) {
        long long val_a = rnd.next(100000LL, 1000000000LL);
        long long val_w = rnd.next(10000LL, 1000000LL);
        for(int i = 0; i < n; i++) a[i] = val_a;
        for(int i = 0; i < k; i++) w[i] = val_w;
    } else if (test_id == 3 || test_id == 14) {
        long long val_a = rnd.next(-1000000000LL, -100000LL);
        long long val_w = rnd.next(10000LL, 1000000LL);
        for(int i = 0; i < n; i++) a[i] = val_a;
        for(int i = 0; i < k; i++) w[i] = val_w;
    } else if (test_id == 46 || test_id == 47) {
        for(int i = 0; i < n; i++) a[i] = (i % 2 == 0) ? 1000000000LL : -1000000000LL;
        for(int i = 0; i < k; i++) w[i] = rnd.next(-1000000LL, 1000000LL);
    } else {
        for(int i = 0; i < n; i++) a[i] = rnd.next(-1000000000LL, 1000000000LL);
        for(int i = 0; i < k; i++) w[i] = rnd.next(-1000000LL, 1000000LL);
    }

    // In input
    fin << n << " " << k << "\n";
    for (int i = 0; i < n; ++i) fin << a[i] << (i == n - 1 ? "" : " ");
    fin << "\n";
    for (int i = 0; i < k; ++i) fin << w[i] << (i == k - 1 ? "" : " ");
    fin << "\n";
    fin.close();

    // In output
    auto[ans_val, ans_ways] = solve(n, k, a, w);
    fout << ans_val << "\n" << ans_ways << "\n";
    fout.close();

    cout << "Generated Test " << setw(2) << test_id 
         << " (Subtask " << subtask << ") - n: " << n << ", k: " << k << "\n";
}

int main(int argc, char* argv