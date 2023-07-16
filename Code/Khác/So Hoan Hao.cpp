#include<iostream>
using namespace std;
int main()
{
    long a, i = 1, t = 0;
    cin>>a;
    while ( i <= a/2 )
    {
        if (a%i == 0)
          t += i;
    }
    if (t == a)
        cout<<"YES";
    else
        cout<<"NO";
}
