#include<bits/stdc++.h>
using namespace std; 
int main()
{ 
    double a, b, c, delta, x1, x2;
    cout<<fixed<<setprecision(5);
    cin >> a;
    
    cin >> b;
    
    cin >> c;
    if(a == 0) {
        // a== 0 phuong trinh tro thanh phuong trinh bac mot bx + c = 0
        if(b == 0) {
            if (c == 0) {
                cout << "VSN" ;
            } else {
                cout << "VN";
            }
        } else {
            cout << -c/b ;
        }
    } else {
        delta = b*b - 4*a*c;
        if(delta > 0) {
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
            cout << x2 <<" "<< x1;
        } else if ( delta == 0) {
            cout <<-b/2*a << endl;
        } else {
            cout << "VN" << endl;
        }
    }
    return 0;
}