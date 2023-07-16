#include <bits/stdc++.h>
using namespace std;
int check(string s){
	int d=0, x=0;
	for (int i=0;i < s.length();i++)
	{
		if (s[i]=='(') d++;
		else d--;
		if (d==0) {
			x=i;
		}
		if (d<0) break;
	}
	return x+1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LBRACKET.inp","r",stdin);
	freopen("LBRACKET.out","w",stdout);
	string s,s1;
	int m=0,ans=0;
	cin >> s;
	for (int i=0; i < s.length();i++)
	{
		s1 = "";
		for (int j=i;j<s.length();j++)
		{
			s1=s1+s[j];
		}
		int tmp=check(s1);
		if (tmp>0) {
			if (m<tmp) {
				m=tmp;
				ans=i;
			}
		}
	}
	if (m==0) cout << 0; else {
			cout << m << endl;
			cout << ans+1 << " " << m+ans;
	}
	return 0;
}
