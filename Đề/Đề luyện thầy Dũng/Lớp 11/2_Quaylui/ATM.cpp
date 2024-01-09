#define taskname "ATM"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using lli = long long;
const int maxN = 41;
const int maxNZ = 1 << 20;

int n, m, k;
int a[maxN];
int nz;
int z[maxNZ];
lli Result;

void ReadInput()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

//Thử quyết định chọn/không chọn cho tờ tiền thứ i
//q: Số tiền đã trả được qua việc chọn/không chọn các tờ tiền từ 1 tới i - 1
void AttemptFirst(int i, int q)
{
    if (i > k)
    {
        z[nz++] = q;
        return;
    }
    AttemptFirst(i + 1, q); //Không chọn tờ tiền i
    if (q + a[i] <= m)
        AttemptFirst(i + 1, q + a[i]); //Có chọn tờ tiền i
}

void AttemptSecond(int i, int q)
{
    if (i > n)
    {
        Result +=
            upper_bound(z, z + nz, m - q) -
            lower_bound(z, z + nz, m - q);
        return;
    }
    AttemptSecond(i + 1, q);
    if (q + a[i] <= m)
        AttemptSecond(i + 1, q + a[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    k = n / 2;
    nz = 0;
    AttemptFirst(1, 0);
    sort(z, z + nz);
    Result = 0;
    AttemptSecond(k + 1, 0);
    cout << Result;
}
