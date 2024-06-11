#include "testlib.h"
#include<bits/stdc++.h>

int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt(); 
    std::vector<long long> a(n + 2);

    for (int i = 1; i <= n; ++i) {
        a[i] = inf.readLong();  
    }

    long long check = ans.readLong();

    int p = ouf.readInt(), q = ouf.readInt();

    if(p < 1 || q < 1 || q > n || q > n || q == p)
        quitf(_wa, "chi so khong thoa man");

    if(a[q] * a[p] == check)
        quitf(_ok, "ket qua dung");
    else {
        if(a[q] * a[p] > check)
            quitf(_wa, "chua toi uu, ans:%lld, a[p]:%lld, a[q]:%lld, a[p]*a[q]:%lld", check, a[p], a[q], a[q]*a[p]);
        else 
            quitf(_wa, "toi uu hon ans, ans:%lld, a[p]:%lld, a[q]:%lld, a[p]*a[q]:%lld", check, a[p], a[q], a[q]*a[p]);
    }
    // int p_ouf = ouf.readInt();  // Đọc giá trị p từ output của thí sinh

    // if(check == -1 && p_ouf != -1)
    //     quitf(_wa, "ket qua phai la -1");
    
    // if(check != -1 && p_ouf == -1)
    //     quitf(_wa, "ket qua khac -1");
        
    // int q_ouf = ouf.readInt();  // Đọc giá trị q từ output của thí sinh

    // if (a[p_ouf] + a[q_ouf] == k) {
    //     quitf(_ok, "dung");
    // }

    // quitf(_wa, "ket qua sai");

    // if (p_ouf < 1 || p_ouf > n || q_ouf < 1 || q_ouf > n || (p_ouf == q_ouf)) {
    //     quitf(_wa, "Contestant's output contains invalid indices.");
    // }


    // quitf(_ok, "The contestant's output is correct.");
}
