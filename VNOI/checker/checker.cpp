#include "testlib.h"
#include<string>

using namespace std;

int main(int argc, char * argv[]) {
    // Khởi tạo checker với các tham số đầu vào từ command line
    registerTestlibCmd(argc, argv);

    string a = inf.readString();
    string b = inf.readString();
    string c = ouf.readString();
    string d = ans.readString();

    if(c.size() != d.size()) 
        quitf(_wa, "dap an sai");

    int i = 0, j = 0, k = 0;

    while(i < a.size() && j < b.size() && k < c.size()) {
        if(a[i] == b[j] && b[j] == c[k])
            i++, j++, k++;
        if(a[i] != c[k]) 
            i++;
        if(b[j] != c[k]) 
            j++;
    }

    if(k == c.size()) 
        quitf(_ok, "xau hop le");
    else 
        quitf(_wa, "xau khong thoa man");
}
