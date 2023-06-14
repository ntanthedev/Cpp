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
                cout<<"True";
            else
                cout<<"False";

        }
    else
    {
        if (t<=z)
            cout<<"True";
        else
            cout<<"False";
    }

}
