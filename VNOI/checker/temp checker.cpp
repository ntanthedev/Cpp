#include "testlib.h"
#include <vector>
#include <unordered_map>
#include <cstdlib>

int main(int argc, char * argv[]) {
    // Khởi tạo checker với các tham số đầu vào từ command line
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();  // Đọc số lượng phần tử từ file input
    long long k = inf.readLong();  // Đọc giá trị k từ file input
    std::vector<long long> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        a[i] = inf.readLong();  
    }

    int check = ans.readInt();

    int p_ouf = ouf.readInt();  // Đọc giá trị p từ output của thí sinh

    if(check == -1 && p_ouf != -1)
        quitf(_wa, "ket qua phai la -1");
    
    if(check != -1 && p_ouf == -1)
        quitf(_wa, "ket qua khac -1");
        
    int q_ouf = ouf.readInt();  // Đọc giá trị q từ output của thí sinh

    if (a[p_ouf] + a[q_ouf] == k) {
        quitf(_ok, "dung");
    }

    quitf(_wa, "ket qua sai");

    // if (p_ouf < 1 || p_ouf > n || q_ouf < 1 || q_ouf > n || (p_ouf == q_ouf)) {
    //     quitf(_wa, "Contestant's output contains invalid indices.");
    // }


    // quitf(_ok, "The contestant's output is correct.");
}
