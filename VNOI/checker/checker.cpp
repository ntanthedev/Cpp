#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int a[1000099],h[1000099];
int n;
int main(int argc, char** argv) {
    // Khởi tạo checker với các tham số đầu vào từ command line
    registerTestlibCmd(argc, argv);

    int i,k,ok=1;

    n = inf.readInt();
    for(int j=1;j<=n;j++) a[j] = inf.readInt();
    for(int j=1;j<=n;j++) h[j]=0;

    i = ouf.readInt(), k = ouf.readInt(); //Du lieu cua hoc sinh
    a[i]=k;
    sort(a+1,a+n+1);
    for(int j=1;j<=n;j++)
      if(a[j]!=j)
     {
          ok=0;
          break;
     }


    if (ok==1) {
            quitf(_ok, "ket qua dung");
        }

    else {
        quitf(_wa, "ket qua sai");
    }
}
