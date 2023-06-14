#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, i, ucln = 1, t;
    cin>>a>>b;
    if (a==0 && b==0)
    {
        cout<<"False";
    }
    else if (a!=0 && b==0)
        {
            ucln = abs(a);
            cout<< ucln;
        }
    else if (a==0 && b != 0)
        {
            ucln = abs(b);
            cout<< ucln;
        }
    else
    {
        if (a<=b)
            t = a;
        else
            t = b;
        for( i = 1; i <= t; i++)
        {
            if (a%i == 0 && b%i == 0)
              {
                  ucln = i;
              }
        }
    }
    cout<<ucln;
}
