#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int a, b, c, d, x, y, z, t;
    cin>>a>>b>>c>>d;
    x=b-a;
    z=d-c;
    y=c-a;
    t=a-c;
    if (c>=a)
        {
            if (y<=x)
                //giao nhau voi [a,b] nam truoc [c,d]
            {
                if (d>=b)
                    cout<<d-a;
                else
                    cout<<b-a;
            }

            else
                cout<<(b-a)+(d-c);

        }
    else
    {
        if (t<=z)
            {
                if (d>=b)
                    cout<<d-c;
                else
                    cout<<b-c;
            }
        else
            cout<<(d-c)+(b-a);
    }
}

