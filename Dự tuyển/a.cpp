#include <bits/stdc++.h>
using namespace std;
long long a, s = 0, n = 0, b;
int main() {
    cin >> a >> b;

    for(int i = 1; i <= b; i++) {
        n += i;
    }
    cout << n << '\n';

    for(int i = 1; i <= b; i++) {
        if(i % 2 == 0) {
            s += i;
        }
    }
    cout << s << endl;
}