#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    long long ans_s = ans.readLong(), out_s = ouf.readLong();

    if(ans_s != out_s) 
        quitf(_wa, "kich thuoc khong toi uu");
    
    long long n = inf.readLong(), aa = inf.readLong(), bb = inf.readLong();
    long long a = ouf.readLong(), b = ouf.readLong();

    if(a * b != ans_s)
        quitf(_wa, "kich thuoc phong chua chinh xac");

    if(a > b) swap(a, b);
    if(aa > bb) swap(aa, bb);

    if(a < aa || b < bb)
        quitf(_wa, "kich thuoc mo rong am");

    quitf(_ok, "ket qua dung");
}