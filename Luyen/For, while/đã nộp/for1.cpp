#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long  i, n, t = 0;
    cin>>n;
    for (i=2; i<= n ; i++)
    {
       if (i != 0 && i != 1)
       {
       for (j = 2; j <= i/2 ; j++)
       {
           if (i%j == 0)
           {
            t = 0;
            break;
           }
           else
            t = 1;
        }
        if (t == 1)
            cout << i;
        else
            cout <<" !";
        }
    }

}
