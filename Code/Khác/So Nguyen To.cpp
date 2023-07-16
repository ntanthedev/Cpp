#include<bits/stdc++.h>
using namespace std;

int main()
{
    long i = 2, kt = 1, a;
    cin >> a;
    if (a != 0 && a != 1)
    {
        while(i <= a/2)
            {
                if (a%i == 0)
        {
            kt  = 0;
            break;
        }
            i++;
            }
    }
    else
        kt = 0;
    if (kt == 1)
        cout <<  a << " la so nguyen to";
    else
        cout << a << " ko phai la so nguyen to";
}
