#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;
#define el inp<<'\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const int btest = 251; 
const int etest = 300; // so luong test
const int s1 = 50; //% so luong test theo tung sub
const int s2 = 50 * 2;
const int s3 = 50 * 3;
const int s4 = 50 * 4;
const int s5 = 50 * 5;
const int s6 = 50 * 6;


ll Rand(ll l, ll h)
{
    return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

#define maxn 2003
//#define A 1000000000
const ll A = 1e18;
const ll H = 1e15;
const ll N = 1e3;
const ll Q = 1e5;
const ll X = 2e9;
const ll K = 1e9;
const ll W = 1e6;
const ll T = 10;
mt19937 rd(static_cast<unsigned int>(std::time(nullptr)));

int cal(int x, int n) {
    return double(n / 100.0) * x;
}

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll res = 0, n;
    
    n = (x <= cal(50, s1) ? Rand(5, 20) : Rand(19, 20));
    vector<long long> vt(n);

    if(x <= cal(50, s1)) {
        f0(i, n) {
            if(i < cal(65, n)) 
                vt[i] = Rand(1, 100);
            else 
                vt[i] = Rand(1, N);            
        }
    }
    else if(x <= cal(75, s1)) {
        f0(i, n) {
            if(i < cal(65, n)) 
                vt[i] = Rand(1, N);
            else 
                vt[i] = Rand(1, W);            
        }
    }
    else {
        f0(i, n) {
            if(i < cal(70, n)) 
                vt[i] = Rand(1, N);
            else 
                vt[i] = Rand(1, K);  
            if(x == s1)
                vt[i] = Rand(K - W, K);          
        }
    }

    int lt = Rand(0, n - 1);
    int rt = Rand(lt, n - 1);

    for(int i = lt; i <= rt; i++) {
        res += vt[i];
    }

    ll lmin = *min_element(all(vt));

    ll l = max(Rand(0LL, lmin), res - Rand(1, max(100LL, 2 * lmin))), r = res + Rand(1, max(100LL, 2 * lmin));

    if(l > r) 
        swap(l, r);

    inp << n << " " << l << " " << r << '\n';

    random_shuffle(all(vt));
    random_shuffle(all(vt));

    for(auto i : vt) 
        inp << i << " ";
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll res = 0, n;
    
    n = (x <= s1 + cal(50, s2 - s1) ? Rand(20, 40) : Rand(39, 40));
    vector<long long> vt(n);

    if(x <= s1 + cal(50, s2 - s1)) {
        f0(i, n) {
            if(i < cal(65, n)) 
                vt[i] = Rand(1, 100);
            else 
                vt[i] = Rand(1, N);            
        }
    }
    else if(x <= s1 + cal(75, s2 - s1)) {
        f0(i, n) {
            if(i < cal(65, n)) 
                vt[i] = Rand(1, N);
            else 
                vt[i] = Rand(1, W);            
        }
    }
    else {
        f0(i, n) {
            if(i < cal(70, n)) 
                vt[i] = Rand(1, N);
            else 
                vt[i] = Rand(1, K); 
            if(x == s2)
                vt[i] = Rand(K - W, K);            
        }
    }

    int lt = Rand(0, n - 1);
    int rt = Rand(lt, n - 1);

    for(int i = lt; i <= rt; i++) {
        res += vt[i];
    }

    ll lmin = *min_element(all(vt));

    ll l = max(Rand(0LL, lmin), res - Rand(1, max(100LL, 2 * lmin))), r = res + Rand(1, max(100LL, 2 * lmin));

    if(l > r) 
        swap(l, r);

    inp << n << " " << l << " " << r << '\n';

    random_shuffle(all(vt));
    random_shuffle(all(vt));

    for(auto i : vt) 
        inp << i << " ";
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    ll res = 0, n;
    
    n = (x <= s2 + cal(50, s3 - s2) ? Rand(50, 80) : Rand(77, 80));
    vector<long long> vt(n);

    if(x <= s2 + cal(50, s3 - s2)) {
        f0(i, n) {
            if(i <= cal(65, n)) 
                vt[i] = Rand(1, N);
            else 
                vt[i] = Rand(1, Q);            
        }
    }
    else if(x <= s2 + cal(75, s3 - s2)) {
        f0(i, n) {
            if(i < cal(65, n)) 
                vt[i] = Rand(1, 5 * N);
            else 
                vt[i] = Rand(1, Q);            
        }
    }
    else {
        f0(i, n) {
            if(i < cal(70, n)) 
                vt[i] = Rand(1, 5 * N);
            else 
                vt[i] = Rand(1, Q); 
            if(x == s3)
                vt[i] = Rand(1, Q);            
        }
    }

    int lt = Rand(0, n - 1);
    int rt = Rand(lt, n - 1);

    for(int i = lt; i <= rt; i++) {
        res += vt[i];
    }

    while(lt <= rt && res > Q) {
        res -= vt[rt];
        rt--;
    }

    ll lmin = *min_element(all(vt));

    inp << n << " " << max(Rand(0LL, 2 * lmin), res - Rand(1, max(100LL, 2 * lmin))) << " " << min(res + Rand(1, max(100LL, 2 * lmin)), Q) << '\n';

    random_shuffle(all(vt));
    random_shuffle(all(vt));

    for(auto i : vt) 
        inp << i << " ";
}

void sub4(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    
    ll res = 0, n;
    
    n = (x <= s3 + cal(50, s4 - s3) ? Rand(1, 2 * Q) : Rand(Q, 2 * Q));
    if(x >= cal(80, s4))
        n = 2 * Q;

    vector<long long> vt(n);

    ll w = (x <= s3 + cal(50, s4 - s3) ? Rand(1, K) : Rand(1e8, K)), cnt = Rand(1, n);

    res = w * cnt;

    ll l = max(0LL, res - Rand(1, Rand(1, 15) * w)), r = min(res + Rand(1, Rand(1, 15) * w), w * n); 

    inp << n << " " << l << " " << r << '\n';

    for(int i = 1; i <= n; i++) 
        inp << w << " ";
}

void sub5(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
   
    ll res = 0, n;
    const ll max_r = 1e9 + 5e4;
    
    n = (x <= s4 + cal(50, s5 - s4) ? Rand(1, 2 * Q) : Rand(Q, 2 * Q));
    if(x >= s4 + cal(80, s5 - s4))
        n = 2 * Q;
    vector<long long> vt(n);

    for(int i = 0; i < n; i++) 
        vt[i] = i + 1;

    random_shuffle(all(vt));

    int lt = Rand(0, n - 1);
    int rt = Rand(lt, n - 1);

    int tt = rd() % 10;

    for(int i = lt; i <= rt; i++) {
        res += vt[i];
    }

    ll lmin = *min_element(all(vt));

    ll l = max(0LL, res - Rand(1, Rand(50, 100))), r = res + Rand(1, Rand(50, 100));
    
    if(tt % 5 == 0)
        l = r = lt;

    inp << n << " " << l << " " << r << '\n';

    sort(all(vt));

    for(auto i : vt) 
        inp << i << " ";    
}

void sub6(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    
    const ll NMax = 46116860184273;
    ll res = 0, n;
    
    n = (x <= s5 + cal(50, s6 - s5) ? Rand(1e4, 2 * Q) : Rand(Q, 2 * Q));
    if(x >= s5 + cal(85, s6 - s5))
        n = 2 * Q;

    vector<long long> vt(n);

    for(int i = 0; i < n; i++) {
        vt[i] = Rand(1, NMax);
        if(i < cal(69, n))
            vt[i] = Rand(1, W);
    }
    
    random_shuffle(all(vt));

    ll lmax = *max_element(all(vt)), lmin = *min_element(all(vt));
    ll range = lmax - lmin;
    
    ll lt = Rand(0, n - 1);
    if(x < s5 + cal(50, s6 - s5)) 
        lt = min(lt, Rand(0, min(5 * N, n - 1)));
    ll rt = Rand(lt, n - 1);

    res = 0;
    for(int i = lt; i <= rt; i++) {
        if(res + vt[i] >= min(range + Rand(1, 2) * lmin, H - Rand(1, X))) {
            rt = i;
            break;
        }
        res += vt[i];
    }

    while(res < range) {
        res += vt[rt];
        rt++;
    }

    for(int i = rt, z = Rand(2, 10); i <= rt + z; i++) {
        if(res + vt[i] > H - Rand(1, X))
            break;
        else 
            res += vt[i];
    }

    ll r = min(H - Rand(0, 100), res + Rand(1, W));
    ll l = res - range - Rand(1, 50);

    inp << n << " " << l << " " << r << '\n';

    random_shuffle(all(vt));

    for(auto i : vt) 
        inp << i << " ";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));    

    for (int i = btest; i <= etest; i++)
    {
        if(i <= s1)
            sub1(i);
        else if(i <= s2)
            sub2(i);
        else if(i <= s3)
            sub3(i);
        else if(i <= s4)
            sub4(i);
        else if(i <= s5)
            sub5(i);
        else 
            sub6(i);
    }
    return 0;
}

/*
- l == r
- nhieu so lon, nho xen ke
- gioi han ve 1 phia 
- gioi han ve 2 phia 
- trinh cham check chi so tang dan
*/