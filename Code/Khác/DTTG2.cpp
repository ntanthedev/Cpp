#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b,c;
    double P,S;
    cin>>a>>b>>c;
    if (a+b>c)
    {
        if (a+c>b)
        {
            if (b+c>a)
            {
                P =(a+b+c)/2;
                S = sqrt(P*(P-a)*(P-b)*(P-c));
                cout << (float)S ;
            }
            else
                cout<< "-1" ;
        }
        else
            cout << "-1";
    }
        else
            cout << "-1";



}
