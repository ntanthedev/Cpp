#include<bits/stdc++.h>
using namespace std;
int main()
{
    long double a,b,c;
    long double Denta, x1, x2;
    cin>>a>>b>>c;
    Denta = (b*b)-(4*a*c);
    if (Denta>0)
       {
            x1=(-b-sqrt(Denta))/(2*a);
            x2=(-b+sqrt(Denta))/(2*a);
            if(x1<x2)
            {
                cout<<fixed<<setprecision(5);
                cout << x1 <<'\n';
                cout<<fixed<<setprecision(5);
                cout << x2 <<'\n';

            }
            else
            {
               cout <<fixed<<setprecision(5);
               cout <<x2 <<'\n';
                cout << fixed<<setprecision(5) ;
                cout <<  x1 << '\n';

            }
        }
    else if (Denta<0)
        {
        cout<<"Vo nghiem";
        }
    else
        {
            x1 = (-b)/a ;
            cout<<fixed<<setprecision(5);
            cout << x1 << '\n';
        }



}
