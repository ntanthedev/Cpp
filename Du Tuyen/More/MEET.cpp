using namespace std;

int n, m, c0, d0;
int f[1100][11][110];
int a[11], b[11], c[11], d[11];

int cal (int n, int m, int s) {
if (f[n] [m] [s] != -1) return f[n] [m] [s];

if (m == 0)
return f[n] [m] [s] = (n / c0) * do;|

f[n] [m] [s] = cal (n, m - 1, a[m - 1] / b[m - 1]);
if (n >= c[m] and s > 0) f[n] [m] [s] = max (f[n] [m] [s], cal (n - c[m], m, s - 1) + d[m]);

return f[n] [m] [s];

lint main () {
cin >> n >> m >> c0 >> d0;
for (int i = 1; i <= m; ++i)
cin >> a[i] >> b[i] >> c[i] >> d[i];

a[0] = b[0] = 1;
memset (f, -1, sizeof (f) ) ;
cout << cal (n, m, a[m] / b[m]);