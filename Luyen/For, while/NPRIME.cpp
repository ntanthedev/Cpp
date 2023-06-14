#include <bits/stdc++.h>
using namespace std;
bool nt(long long n)
{
	if (n==1) return false;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0) return false;
	return true;
}
int main()
{
	long long n;
	freopen("NPRIME.inp","r",stdin);
	freopen("NPRIME.out","w",stdout);
	cin >> n;
	for (long long i=sqrt(n);i<=1e18;i++)
        {
			if (nt(i)==true && i*i >= n)
			{
				cout << i*i; break;
			}
        }
	return 0;
}
