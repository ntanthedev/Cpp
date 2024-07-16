//#define _GLIBCXX_DEBUG
 
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;
 
#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T1,typename T2,typename T3>void anss(T1 x,T2 y,T3 z){ans(x!=y,x,z);};  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T>void debug(PQ<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(QP<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";os<<"|"; return os;}
template<typename T>void rearrange(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<int>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return make_pair(v[i],i)<make_pair(v[j],j);});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return make_pair(v[i],-i)>make_pair(v[j],-j);});
  return ord;
}
template<typename T> vector<T> inv_perm(const vector<T>&ord){
  vector<T>inv(ord.size());
  for(int i=0;i<ord.size();i++)inv[ord[i]] = i;
  return inv;
}
ll FLOOR(ll n,ll div){assert(div>0);return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){assert(div>0);return n>=0?(n+div-1)/div:n/div;}
ll digitsum(ll n){ll ret=0;while(n){ret+=n%10;n/=10;}return ret;}
ll modulo(ll n,ll d){return (n%d+d)%d;};
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
ll MULT(ll x,ll y){if(LLONG_MAX/x<=y)return LLONG_MAX;return x*y;}
ll POW2(ll x, ll k){ll ret=1,mul=x;while(k){if(mul==LLONG_MAX)return LLONG_MAX;if(k&1)ret=MULT(ret,mul);mul=MULT(mul,mul);k>>=1;}return ret;}
ll POW(ll x, ll k){ll ret=1;for(int i=0;i<k;i++){if(LLONG_MAX/x<=ret)return LLONG_MAX;ret*=x;}return ret;}
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge():id(-1){};
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};
 
template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T>revgraph(const Graph<T> &g){
  Graph<T>ret(g.size());
  for(int i=0;i<g.size();i++){
    for(auto e:g[i]){
      int to = e.to;
      e.to = i;
      ret[to].push_back(e);
    }
  }
  return ret;
}
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v;
    T w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
template<typename T>
struct Compress{
    vector<T>v;
    Compress(){
    }
    Compress(const vector<T>&input){
        add(input);
    build();
    }
  template<typename... Args>
  Compress(const vector<T> &head,const Args& ...input){
    add(head, input...);
    build();
  }
  template<typename... Args>
  Compress(const T &head,const Args& ...input){
    add(head, input...);
    build();
  }
  void build(){
        sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
  }
    void add(const vector<T>&add){
        v.insert(v.end(),add.begin(), add.end());
    }
  template<typename Head, typename ...Tail>
  void add(const Head& head,const Tail& ...tail){
    add(head);
    add(tail...);
  }
  void add(T val){
    v.push_back(val);
  }
  int next(T val){
    return lower_bound(v.begin(), v.end(), val) - v.begin();
  }
  int prev(T val){
    return upper_bound(v.begin(), v.end(), val) - v.begin() - 1;
  }
  bool exist(T val){
    return binary_search(v.begin(), v.end(), val);
  }
  T val(int x){
    return v[x];
  }
  vector<int>compress(const vector<T>&input){
    vector<int>ret(input.size());
    for(int i=0;i<input.size();i++)ret[i]=next(input[i]);
    return ret;
  }
  int operator[](T val){
    return next(val);
  }
  int size(){
    return v.size();
  }
};
template<typename C>
struct IntervalAddEmptyCount {
  int sz, height, n;
  vector< C > data;
  vector< int > lazy;
  const C M1 = 0;
  const int OM0 = 0;
  IntervalAddEmptyCount(int n){
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }
 
  void set(ll k, const C &x) {
    data[k + sz] = x;
  }
 
  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = data[2 * k + 0] + data[2 * k + 1];
    }
  }
 
  inline C reflect(int k) {
    return lazy[k] == OM0 ? data[k] : 0;
  }
 
  inline void recalc(int k) {
    while(k >>= 1) data[k] = reflect(2 * k + 0) + reflect(2 * k + 1);
  }
 
  void update(int a, int b, const int &x) {
    if(a>=b)return;
    a += sz;
    b += sz - 1;
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] += x, ++l;
      if(r & 1) --r, lazy[r] += x;
    }
    recalc(a);
    recalc(b);
  }
 
  C query() {
    return data[1];
  }
};
template<typename C>
ll rectangle_union(vector<tuple<C,C,C,C>>&add){
  ll ret = 0;
  vector<C>xc,yc;
  int n=add.size();
  xc.reserve(2*n);
  yc.reserve(2*n);
  for(int i=0;i<add.size();i++){
    auto [xl,xr,yl,yr]=add[i];
    xc[2*i]=xl,xc[2*i+1]=xr;
    yc[2*i]=yl,yc[2*i+1]=yr;
  }
  vector<int>ox(2*n),oy(2*n);
  iota(ALL(ox),0);iota(ALL(oy),0);
  sort(ALL(ox),[&](int i,int j){return xc[i]<xc[j];});
  sort(ALL(oy),[&](int i,int j){return yc[i]<yc[j];});
  auto iy=inv_perm(oy);
  IntervalAddEmptyCount<int> seg(2*n);
  for(int i=0;i<2*n-1;i++){
    seg.set(i,yc[oy[i+1]]-yc[oy[i]]);
  }
  seg.build();
  int all = yc[oy.back()] - yc[oy[0]];
  for(int i=0;i<ox.size()-1;i++){
    int k=ox[i]/2;
    if(ox[i]&1)seg.update(iy[2*k],iy[2*k+1],-1);
    else seg.update(iy[2*k],iy[2*k+1],+1);
    ll tmp=seg.query();
    ret+=(all-tmp)*(xc[ox[i+1]]-xc[ox[i]]);
  }
  return ret;
}
namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
uint32_t pil = 0, pir = 0, por = 0;
 
struct Pre {
  char num[40000];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = n % 10 + '0';
        n /= 10;
      }
    }
  }
} constexpr pre;
 
__attribute__((target("avx2"), optimize("O3"))) inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
}
 
__attribute__((target("avx2"), optimize("O3"))) inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}
 
inline void rd(char& c) { c = ibuf[pil++]; }
 
template <typename T>
__attribute__((target("avx2"), optimize("O3"))) inline void rd(T& x) {
  if (pil + 32 > pir) load();
  char c;
  do
    rd(c);
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value) {
    if (c == '-') {
      minus = 1;
      rd(c);
    }
  }
  x = 0;
  while (c >= '0') {
    x = x * 10 + (c & 15);
    rd(c);
  }
  if constexpr (is_signed<T>::value) {
    if (minus) x = -x;
  }
}
 
inline void wt(char c) { obuf[por++] = c; }
template <typename T>
__attribute__((target("avx2"), optimize("O3"))) inline void wt(T x) {
  if (por + 32 > SZ) flush();
  if (!x) {
    wt('0');
    return;
  }
  if constexpr (is_signed<T>::value) {
    if (x < 0) {
      wt('-');
      x = -x;
    }
  }
  if (x >= 10000000000000000) {
    if (x >= 1000000000000000000) {
      uint32_t r1 = x % 100000000;
      uint64_t q1 = x / 100000000;
      uint32_t r2 = q1 % 100000000;
      uint32_t q2 = q1 / 100000000;
      uint32_t n1 = r1 % 10000;
      uint32_t n2 = r1 / 10000;
      uint32_t n3 = r2 % 10000;
      uint32_t n4 = r2 / 10000;
      memcpy(obuf + por, pre.num + (q2 << 2) + 1, 3);
      memcpy(obuf + por + 3, pre.num + (n4 << 2), 4);
      memcpy(obuf + por + 7, pre.num + (n3 << 2), 4);
      memcpy(obuf + por + 11, pre.num + (n2 << 2), 4);
      memcpy(obuf + por + 15, pre.num + (n1 << 2), 4);
      por += 19;
    } else if (x >= 100000000000000000) {
      uint32_t r1 = x % 100000000;
      uint64_t q1 = x / 100000000;
      uint32_t r2 = q1 % 100000000;
      uint32_t q2 = q1 / 100000000;
      uint32_t n1 = r1 % 10000;
      uint32_t n2 = r1 / 10000;
      uint32_t n3 = r2 % 10000;
      uint32_t n4 = r2 / 10000;
      obuf[por + 0] = '0' + q2 / 10;
      obuf[por + 1] = '0' + q2 % 10;
      memcpy(obuf + por + 2, pre.num + (n4 << 2), 4);
      memcpy(obuf + por + 6, pre.num + (n3 << 2), 4);
      memcpy(obuf + por + 10, pre.num + (n2 << 2), 4);
      memcpy(obuf + por + 14, pre.num + (n1 << 2), 4);
      por += 18;
    } else {
      uint32_t r1 = x % 100000000;
      uint64_t q1 = x / 100000000;
      uint32_t r2 = q1 % 100000000;
      uint32_t q2 = q1 / 100000000;
      uint32_t n1 = r1 % 10000;
      uint32_t n2 = r1 / 10000;
      uint32_t n3 = r2 % 10000;
      uint32_t n4 = r2 / 10000;
      obuf[por + 0] = '0' + q2;
      memcpy(obuf + por + 1, pre.num + (n4 << 2), 4);
      memcpy(obuf + por + 5, pre.num + (n3 << 2), 4);
      memcpy(obuf + por + 9, pre.num + (n2 << 2), 4);
      memcpy(obuf + por + 13, pre.num + (n1 << 2), 4);
      por += 17;
    }
  } else {
    int i = 8;
    char buf[12];
    while (x >= 10000) {
      memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
      x /= 10000;
      i -= 4;
    }
    if (x < 100) {
      if (x < 10) {
        wt(char('0' + x));
      } else {
        obuf[por + 0] = '0' + x / 10;
        obuf[por + 1] = '0' + x % 10;
        por += 2;
      }
    } else {
      if (x < 1000) {
        memcpy(obuf + por, pre.num + (x << 2) + 1, 3);
        por += 3;
      } else {
        memcpy(obuf + por, pre.num + (x << 2), 4);
        por += 4;
      }
    }
    memcpy(obuf + por, buf + i + 4, 8 - i);
    por += 8 - i;
  }
}
 
struct Dummy {
  Dummy() { atexit(flush); }
} dummy;
 
}  // namespace fastio
using fastio::rd;
using fastio::wt;
struct RandomNumberGenerator {
  mt19937_64 mt;
 
  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  RandomNumberGenerator(int x) : mt(x){
    cout<<"-----debug-----"<<endl;
  }
  ll operator()(ll a, ll b) { // [a, b)
    uniform_int_distribution< ll > dist(a, b - 1);
    return dist(mt);
  }
 
  ll operator()(ll b) { // [0, b)
    return (*this)(0, b);
  }
};
RandomNumberGenerator rng;
int main(){
  //cin.tie(nullptr);
  //ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  {}
  vector<tuple<int,int,int,int>>add;
  int n;
  rd(n);
  add.reserve(2*n);
  //int n;cin>>n;
  rep(i,0,n){
    /*int l=rng(1,1e9);
    int d=rng(1,1e9);
    int r=rng(1,1e9);
    int u=rng(1,1e9);*/
    int l,d,r,u;
    rd(l);
    rd(d);
    rd(r);
    rd(u);
    add.EB(l,r,d,u);
  }
  wt(rectangle_union(add));
  wt('\n');
  return 0;
};