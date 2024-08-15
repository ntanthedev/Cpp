#include <bits/stdc++.h>
using namespace std;

// Return sum of product of each element
// with each element after it
long long findSumofProduct(int arr[], int n)
{
    long long suffix_sum = arr[n - 1];

    // Finding product of array elements and
    // suffix sum.
    long long res = 0;
    for (int i = n - 2; i >= 0; i--) {

        res += (suffix_sum * arr[i]);

        // finding suffix sum
        suffix_sum += arr[i];
    }

    return res;
}

const int maxN=1000005;
// Driven Program
int n, arr[maxN];
int main()
{
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    cout << findSumofProduct(arr, n) << endl;
    return 0;
}
