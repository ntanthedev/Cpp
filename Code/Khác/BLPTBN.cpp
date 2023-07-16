#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,x;
    cin >>a>>b;
    if(a==0)
    {
       if(b==0)
       {
           cout<<"Vo so nghiem"<<endl;
       }
       else
       {
           cout<<"Vo nghiem"<<endl;
       }
    }

    else
    {
        x=(double)-b/a;
        cout<<x<<endl;
    }
    return 0;
}
