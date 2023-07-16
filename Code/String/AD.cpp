#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("AD.inp","r",stdin);
    freopen("AD.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string bcc = "abcdefghijklmnopqrstuvwxyz";
	string S1, S2;
	long d1[26], d2[26];
	long res = 0;
	cin>>S1;
	cin>>S2;
	map<char, long long>M1;
	map<char, long long>M2;
	int n = max(S1.size(), S2.size());
	for(int i = 0; i < S1.size(); i++)
		M1[S1[i]]++;
    for(int i = 0 ; i < S2.size(); i++)
        M2[S2[i]]++;
	for(int i = 0; i < 26; i++)
	{
		d1[i] = M1[bcc[i]];
		d2[i] = M2[bcc[i]];
		res = abs(d1[i] - d2[i]) + res;
	}
	cout<<res;
}
