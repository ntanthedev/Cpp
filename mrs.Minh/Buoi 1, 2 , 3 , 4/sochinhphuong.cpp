#include<bits/stdc++.h> 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int sqr = sqrt(n);
    freopen("sochinhphuong.inp","r",stdin);
    freopen("sochinhphuong.out","w",stdout);
    if(sqr*sqr == n){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}