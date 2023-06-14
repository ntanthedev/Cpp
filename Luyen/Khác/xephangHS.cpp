#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,d,t;
    cin>>a>>b>>c>>d;
    t=(a+b+(2*c)+(2*d))/6;
    if(t<9)
    {
        if(9>t>=7)
            cout<<"Kha";
        else if(7>t>=5)
            cout<<"Trung Binh";
        else
            cout<<"Yeu";
    }
    else
        cout<<"Gioi";
}
