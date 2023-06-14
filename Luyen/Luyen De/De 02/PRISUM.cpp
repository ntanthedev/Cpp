#include<bits/stdc++.h>
using namespace std;
long long n, S = 2;
bool snt(long long n)
{
	if(n<2)
		return 0;
	for(int i=2;i<=sqrt(n);i++)
		if (n%i==0)
			return 0;
	return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("PRISUM.inp","r",stdin);
    freopen("PRISUM.out","w",stdout);
    cin>>n;
    for(int i = 3; i <= n; i+=2)
        if(snt(i) == 1)
            S += i;
    if(snt(S) == 1)
        cout<<S;
    else
        cout<<-1;
}
