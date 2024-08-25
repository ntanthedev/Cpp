#line 1 "main.cpp"
#line 1 "main.cpp"
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int) (n); i++)
#define rrep(i, n) for(int i = (int) (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
template<class T>
void get_unique(vector<T>& x) {
    x.erase(unique(x.begin(), x.end()), x.end());
}
template<class T>
bool chmax(T& a, const T& b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template<class T>
bool chmin(T& a, const T& b) {
    if(b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template<class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(int i = 0; i < int(v.size()); i++) {
        is >> v[i];
    }
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(int i = 0; i < int(v.size()); i++) {
        os << v[i];
        if(i < sz(v) - 1)
            os << ' ';
    }
    return os;
}

#line 1 "/Users/gyouzasushi/kyopro/library/atcoder/math.hpp"

#line 8 "/Users/gyouzasushi/kyopro/library/atcoder/math.hpp"

#line 1 "/Users/gyouzasushi/kyopro/library/atcoder/internal_math.hpp"

#line 5 "/Users/gyouzasushi/kyopro/library/atcoder/internal_math.hpp"

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

    namespace internal {

        // @param m `1 <= m`
        // @return x mod m
        constexpr long long safe_mod(long long x, long long m) {
            x %= m;
            if(x < 0)
                x += m;
            return x;
        }

        // Fast modular multiplication by barrett reduction
        // Reference: https://en.wikipedia.org/wiki/Barrett_reduction
        // NOTE: reconsider after Ice Lake
        struct barrett {
            unsigned int _m;
            unsigned long long im;

            // @param m `1 <= m < 2^31`
            explicit barrett(unsigned int m)
                : _m(m), im((unsigned long long) (-1) / m + 1) {}

            // @return m
            unsigned int umod() const { return _m; }

            // @param a `0 <= a < m`
            // @param b `0 <= b < m`
            // @return `a * b % m`
            unsigned int mul(unsigned int a, unsigned int b) const {
                // [1] m = 1
                // a = b = im = 0, so okay

                // [2] m >= 2
                // im = ceil(2^64 / m)
                // -> im * m = 2^64 + r (0 <= r < m)
                // let z = a*b = c*m + d (0 <= c, d < m)
                // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r +
                // d*im c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 +
                // m * (m + 1) < 2^64 * 2
                // ((ab * im) >> 64) == c or c + 1
                unsigned long long z = a;
                z *= b;
#ifdef _MSC_VER
                unsigned long long x;
                _umul128(z, im, &x);
#else
                unsigned long long x =
                    (unsigned long long) (((unsigned __int128) (z) *im) >> 64);
#endif
                unsigned int v = (unsigned int) (z - x * _m);
                if(_m <= v)
                    v += _m;
                return v;
            }
        };

        // @param n `0 <= n`
        // @param m `1 <= m`
        // @return `(x ** n) % m`
        constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
            if(m == 1)
                return 0;
            unsigned int _m = (unsigned int) (m);
            unsigned long long r = 1;
            unsigned long long y = safe_mod(x, m);
            while(n) {
                if(n & 1)
                    r = (r * y) % _m;
                y = (y * y) % _m;
                n >>= 1;
            }
            return r;
        }

        // Reference:
        // M. Forisek and J. Jancina,
        // Fast Primality Testing for Integers That Fit into a Machine Word
        // @param n `0 <= n`
        constexpr bool is_prime_constexpr(int n) {
            if(n <= 1)
                return false;
            if(n == 2 || n == 7 || n == 61)
                return true;
            if(n % 2 == 0)
                return false;
            long long d = n - 1;
            while(d % 2 == 0)
                d /= 2;
            constexpr long long bases[3] = {2, 7, 61};
            for(long long a: bases) {
                long long t = d;
                long long y = pow_mod_constexpr(a, t, n);
                while(t != n - 1 && y != 1 && y != n - 1) {
                    y = y * y % n;
                    t <<= 1;
                }
                if(y != n - 1 && t % 2 == 0) {
                    return false;
                }
            }
            return true;
        }
        template<int n>
        constexpr bool is_prime = is_prime_constexpr(n);

        // @param b `1 <= b`
        // @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
        constexpr std::pair<long long, long long> inv_gcd(long long a,
                                                          long long b) {
            a = safe_mod(a, b);
            if(a == 0)
                return {b, 0};

            // Contracts:
            // [1] s - m0 * a = 0 (mod b)
            // [2] t - m1 * a = 0 (mod b)
            // [3] s * |m1| + t * |m0| <= b
            long long s = b, t = a;
            long long m0 = 0, m1 = 1;

            while(t) {
                long long u = s / t;
                s -= t * u;
                m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

                // [3]:
                // (s - t * u) * |m1| + t * |m0 - m1 * u|
                // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
                // = s * |m1| + t * |m0| <= b

                auto tmp = s;
                s = t;
                t = tmp;
                tmp = m0;
                m0 = m1;
                m1 = tmp;
            }
            // by [3]: |m0| <= b/g
            // by g != b: |m0| < b/g
            if(m0 < 0)
                m0 += b / s;
            return {s, m0};
        }

        // Compile time primitive root
        // @param m must be prime
        // @return primitive root (and minimum in now)
        constexpr int primitive_root_constexpr(int m) {
            if(m == 2)
                return 1;
            if(m == 167772161)
                return 3;
            if(m == 469762049)
                return 3;
            if(m == 754974721)
                return 11;
            if(m == 998244353)
                return 3;
            int divs[20] = {};
            divs[0] = 2;
            int cnt = 1;
            int x = (m - 1) / 2;
            while(x % 2 == 0)
                x /= 2;
            for(int i = 3; (long long) (i) *i <= x; i += 2) {
                if(x % i == 0) {
                    divs[cnt++] = i;
                    while(x % i == 0) {
                        x /= i;
                    }
                }
            }
            if(x > 1) {
                divs[cnt++] = x;
            }
            for(int g = 2;; g++) {
                bool ok = true;
                for(int i = 0; i < cnt; i++) {
                    if(pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                    return g;
            }
        }
        template<int m>
        constexpr int primitive_root = primitive_root_constexpr(m);

        // @param n `n < 2^32`
        // @param m `1 <= m < 2^32`
        // @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
        unsigned long long floor_sum_unsigned(unsigned long long n,
                                              unsigned long long m,
                                              unsigned long long a,
                                              unsigned long long b) {
            unsigned long long ans = 0;
            while(true) {
                if(a >= m) {
                    ans += n * (n - 1) / 2 * (a / m);
                    a %= m;
                }
                if(b >= m) {
                    ans += n * (b / m);
                    b %= m;
                }

                unsigned long long y_max = a * n + b;
                if(y_max < m)
                    break;
                // y_max < m * (n + 1)
                // floor(y_max / m) <= n
                n = (unsigned long long) (y_max / m);
                b = (unsigned long long) (y_max % m);
                std::swap(m, a);
            }
            return ans;
        }

    }  // namespace internal

}  // namespace atcoder

#line 10 "/Users/gyouzasushi/kyopro/library/atcoder/math.hpp"

namespace atcoder {

    long long pow_mod(long long x, long long n, int m) {
        assert(0 <= n && 1 <= m);
        if(m == 1)
            return 0;
        internal::barrett bt((unsigned int) (m));
        unsigned int r = 1, y = (unsigned int) (internal::safe_mod(x, m));
        while(n) {
            if(n & 1)
                r = bt.mul(r, y);
            y = bt.mul(y, y);
            n >>= 1;
        }
        return r;
    }

    long long inv_mod(long long x, long long m) {
        assert(1 <= m);
        auto z = internal::inv_gcd(x, m);
        assert(z.first == 1);
        return z.second;
    }

    // (rem, mod)
    std::pair<long long, long long> crt(const std::vector<long long>& r,
                                        const std::vector<long long>& m) {
        assert(r.size() == m.size());
        int n = int(r.size());
        // Contracts: 0 <= r0 < m0
        long long r0 = 0, m0 = 1;
        for(int i = 0; i < n; i++) {
            assert(1 <= m[i]);
            long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
            if(m0 < m1) {
                std::swap(r0, r1);
                std::swap(m0, m1);
            }
            if(m0 % m1 == 0) {
                if(r0 % m1 != r1)
                    return {0, 0};
                continue;
            }
            // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)

            // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
            // r2 % m0 = r0
            // r2 % m1 = r1
            // -> (r0 + x*m0) % m1 = r1
            // -> x*u0*g = r1-r0 (mod u1*g) (u0*g = m0, u1*g = m1)
            // -> x = (r1 - r0) / g * inv(u0) (mod u1)

            // im = inv(u0) (mod u1) (0 <= im < u1)
            long long g, im;
            std::tie(g, im) = internal::inv_gcd(m0, m1);

            long long u1 = (m1 / g);
            // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
            if((r1 - r0) % g)
                return {0, 0};

            // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
            long long x = (r1 - r0) / g % u1 * im % u1;

            // |r0| + |m0 * x|
            // < m0 + m0 * (u1 - 1)
            // = m0 + m0 * m1 / g - m0
            // = lcm(m0, m1)
            r0 += x * m0;
            m0 *= u1;  // -> lcm(m0, m1)
            if(r0 < 0)
                r0 += m0;
        }
        return {r0, m0};
    }

    long long floor_sum(long long n, long long m, long long a, long long b) {
        assert(0 <= n && n < (1LL << 32));
        assert(1 <= m && m < (1LL << 32));
        unsigned long long ans = 0;
        if(a < 0) {
            unsigned long long a2 = internal::safe_mod(a, m);
            ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
            a = a2;
        }
        if(b < 0) {
            unsigned long long b2 = internal::safe_mod(b, m);
            ans -= 1ULL * n * ((b2 - b) / m);
            b = b2;
        }
        return ans + internal::floor_sum_unsigned(n, m, a, b);
    }

}  // namespace atcoder

#line 1 "/Users/gyouzasushi/kyopro/library/atcoder/modint.hpp"

#line 6 "/Users/gyouzasushi/kyopro/library/atcoder/modint.hpp"
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

#line 1 "/Users/gyouzasushi/kyopro/library/atcoder/internal_type_traits.hpp"

#line 7 "/Users/gyouzasushi/kyopro/library/atcoder/internal_type_traits.hpp"

namespace atcoder {

    namespace internal {

#ifndef _MSC_VER
        template<class T>
        using is_signed_int128 =
            typename std::conditional<std::is_same<T, __int128_t>::value ||
                                          std::is_same<T, __int128>::value,
                                      std::true_type, std::false_type>::type;

        template<class T>
        using is_unsigned_int128 = typename std::conditional<
            std::is_same<T, __uint128_t>::value ||
                std::is_same<T, unsigned __int128>::value,
            std::true_type, std::false_type>::type;

        template<class T>
        using make_unsigned_int128 =
            typename std::conditional<std::is_same<T, __int128_t>::value,
                                      __uint128_t, unsigned __int128>;

        template<class T>
        using is_integral =
            typename std::conditional<std::is_integral<T>::value ||
                                          is_signed_int128<T>::value ||
                                          is_unsigned_int128<T>::value,
                                      std::true_type, std::false_type>::type;

        template<class T>
        using is_signed_int =
            typename std::conditional<(is_integral<T>::value &&
                                       std::is_signed<T>::value) ||
                                          is_signed_int128<T>::value,
                                      std::true_type, std::false_type>::type;

        template<class T>
        using is_unsigned_int =
            typename std::conditional<(is_integral<T>::value &&
                                       std::is_unsigned<T>::value) ||
                                          is_unsigned_int128<T>::value,
                                      std::true_type, std::false_type>::type;

        template<class T>
        using to_unsigned = typename std::conditional<
            is_signed_int128<T>::value, make_unsigned_int128<T>,
            typename std::conditional<std::is_signed<T>::value,
                                      std::make_unsigned<T>,
                                      std::common_type<T>>::type>::type;

#else

        template<class T>
        using is_integral = typename std::is_integral<T>;

        template<class T>
        using is_signed_int =
            typename std::conditional<is_integral<T>::value &&
                                          std::is_signed<T>::value,
                                      std::true_type, std::false_type>::type;

        template<class T>
        using is_unsigned_int =
            typename std::conditional<is_integral<T>::value &&
                                          std::is_unsigned<T>::value,
                                      std::true_type, std::false_type>::type;

        template<class T>
        using to_unsigned =
            typename std::conditional<is_signed_int<T>::value,
                                      std::make_unsigned<T>,
                                      std::common_type<T>>::type;

#endif

        template<class T>
        using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

        template<class T>
        using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

        template<class T>
        using to_unsigned_t = typename to_unsigned<T>::type;

    }  // namespace internal

}  // namespace atcoder

#line 14 "/Users/gyouzasushi/kyopro/library/atcoder/modint.hpp"

namespace atcoder {

    namespace internal {

        struct modint_base {};
        struct static_modint_base : modint_base {};

        template<class T>
        using is_modint = std::is_base_of<modint_base, T>;
        template<class T>
        using is_modint_t = std::enable_if_t<is_modint<T>::value>;

    }  // namespace internal

    template<int m, std::enable_if_t<(1 <= m)>* = nullptr>
    struct static_modint : internal::static_modint_base {
        using mint = static_modint;

    public:
        static constexpr int mod() { return m; }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }

        static_modint() : _v(0) {}
        template<class T, internal::is_signed_int_t<T>* = nullptr>
        static_modint(T v) {
            long long x = (long long) (v % (long long) (umod()));
            if(x < 0)
                x += umod();
            _v = (unsigned int) (x);
        }
        template<class T, internal::is_unsigned_int_t<T>* = nullptr>
        static_modint(T v) {
            _v = (unsigned int) (v % umod());
        }

        unsigned int val() const { return _v; }

        mint& operator++() {
            _v++;
            if(_v == umod())
                _v = 0;
            return *this;
        }
        mint& operator--() {
            if(_v == 0)
                _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }

        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if(_v >= umod())
                _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v -= rhs._v;
            if(_v >= umod())
                _v += umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            unsigned long long z = _v;
            z *= rhs._v;
            _v = (unsigned int) (z % umod());
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while(n) {
                if(n & 1)
                    r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            if(prime) {
                assert(_v);
                return pow(umod() - 2);
            } else {
                auto eg = internal::inv_gcd(_v, m);
                assert(eg.first == 1);
                return eg.second;
            }
        }

        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }

    private:
        unsigned int _v;
        static constexpr unsigned int umod() { return m; }
        static constexpr bool prime = internal::is_prime<m>;
    };

    template<int id>
    struct dynamic_modint : internal::modint_base {
        using mint = dynamic_modint;

    public:
        static int mod() { return (int) (bt.umod()); }
        static void set_mod(int m) {
            assert(1 <= m);
            bt = internal::barrett(m);
        }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }

        dynamic_modint() : _v(0) {}
        template<class T, internal::is_signed_int_t<T>* = nullptr>
        dynamic_modint(T v) {
            long long x = (long long) (v % (long long) (mod()));
            if(x < 0)
                x += mod();
            _v = (unsigned int) (x);
        }
        template<class T, internal::is_unsigned_int_t<T>* = nullptr>
        dynamic_modint(T v) {
            _v = (unsigned int) (v % mod());
        }

        unsigned int val() const { return _v; }

        mint& operator++() {
            _v++;
            if(_v == umod())
                _v = 0;
            return *this;
        }
        mint& operator--() {
            if(_v == 0)
                _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }

        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if(_v >= umod())
                _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v += mod() - rhs._v;
            if(_v >= umod())
                _v -= umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            _v = bt.mul(_v, rhs._v);
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while(n) {
                if(n & 1)
                    r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            auto eg = internal::inv_gcd(_v, mod());
            assert(eg.first == 1);
            return eg.second;
        }

        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }

    private:
        unsigned int _v;
        static internal::barrett bt;
        static unsigned int umod() { return bt.umod(); }
    };
    template<int id>
    internal::barrett dynamic_modint<id>::bt(998244353);

    using modint998244353 = static_modint<998244353>;
    using modint1000000007 = static_modint<1000000007>;
    using modint = dynamic_modint<-1>;

    namespace internal {

        template<class T>
        using is_static_modint =
            std::is_base_of<internal::static_modint_base, T>;

        template<class T>
        using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

        template<class>
        struct is_dynamic_modint : public std::false_type {};
        template<int id>
        struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

        template<class T>
        using is_dynamic_modint_t =
            std::enable_if_t<is_dynamic_modint<T>::value>;

    }  // namespace internal

}  // namespace atcoder

#line 4 "/Users/gyouzasushi/kyopro/library/math/factorize.hpp"
long long modmul(long long x, long long y, long long mod) {
    using i128 = __int128_t;
    return (long long) (i128(x) * i128(y) % i128(mod));
}
long long modpow(long long a, long long n, long long mod) {
    long long ret = 1;
    while(n > 0) {
        if(n & 1)
            ret = modmul(ret, a, mod);
        a = modmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}
long long rho(long long n) {
    long long z = 0;
    auto f = [&](long long x) -> long long {
        long long ret = modmul(x, x, n) + z;
        if(ret == n)
            return 0;
        return ret;
    };
    while(true) {
        long long x = ++z;
        long long y = f(x);
        while(true) {
            long long d = std::gcd(std::abs(x - y), n);
            if(d == n)
                break;
            if(d > 1)
                return d;
            x = f(x);
            y = f(f(y));
        }
    }
}
#include <initializer_list>
bool miller_rabin(long long n) {
    if(n == 1)
        return 0;
    long long d = n - 1, s = 0;
    while(~d & 1)
        d >>= 1, s++;
    auto check = [&](long long a) -> bool {
        long long x = modpow(a, d, n);
        if(x == 1)
            return 1;
        long long y = n - 1;
        for(int i = 0; i < s; i++) {
            if(x == y)
                return true;
            x = modmul(x, x, n);
        }
        return false;
    };
    for(long long a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(a >= n)
            break;
        if(!check(a))
            return false;
    }
    return true;
}
#line 59 "/Users/gyouzasushi/kyopro/library/math/factorize.hpp"
std::map<long long, int> factorize(long long n) {
    std::map<long long, int> ret;
    while(~n & 1)
        n >>= 1, ret[2]++;
    std::queue<long long> q;
    q.push(n);
    while(!q.empty()) {
        long long p = q.front();
        q.pop();
        if(p == 1)
            continue;
        if(miller_rabin(p)) {
            ret[p]++;
            continue;
        }
        long long d = rho(p);
        q.push(d);
        q.push(p / d);
    }
    return ret;
}
#line 58 "main.cpp"
struct binomial_coefficient_arbitrary_mod {
    static void sed_mod(int mod) {
        assert(1 <= mod);
        m = mod;
        factors = factorize(m);
        f.assign(factors.size(), {});
        inv_f.assign(factors.size(), {});
        max_p_q = 0;
        for(auto [p, q]: factors) {
            max_p_q = std::max(max_p_q, pow_ll(p, q));
        }
    }
    static long long C(long long n, long long k) {
        if(m == 1 || n < 0 || n < k || k < 0)
            return 0;
        ensure(n);
        long long r = n - k;
        vector<long long> rems(factors.size()), mods(factors.size());
        int id = 0;
        for(auto [p, q]: factors) {
            long long p_q = pow_ll(p, q);
            mods[id] = p_q;
            long long e1 = 0, e2 = 0;
            for(long long p_i = p_q;;) {
                e1 += n / p_i - k / p_i - r / p_i;
                if(p_i > n / p)
                    break;
                p_i *= p;
            }
            for(long long p_i = p;;) {
                e2 += n / p_i - k / p_i - r / p_i;
                if(p_i > n / p)
                    break;
                p_i *= p;
            }
            atcoder::internal::barrett bt((unsigned int) (p_q));
            long long delta = p == 2 && q >= 3 ? 1 : -1;
            long long rem = delta == -1 && e1 & 1 ? p_q - 1 : 1;
            rem = bt.mul(rem, atcoder::pow_mod(p, e2, p_q));
            for(long long p_i = 1;;) {
                rem = bt.mul(rem, f[id][(n / p_i) % p_q]);
                rem = bt.mul(rem, inv_f[id][(k / p_i) % p_q]);
                rem = bt.mul(rem, inv_f[id][(r / p_i) % p_q]);
                if(p_i > n / p)
                    break;
                p_i *= p;
            }
            rems[id] = rem;
            id++;
        }
        return atcoder::crt(rems, mods).first;
    }

private:
    static void ensure(long long n) {
        if(max_size > n)
            return;
        int id = 0;
        for(auto [p, q]: factors) {
            long long p_q = pow_ll(p, q);
            int sz = f[id].size();
            if((long long) sz > std::min(p_q - 1, n) + 1)
                continue;
            f[id].resize(std::min(p_q - 1, n) + 1);
            inv_f[id].resize(std::min(p_q - 1, n) + 1);
            max_size = std::max(max_size, std::min(p_q - 1, n) + 1);
            atcoder::internal::barrett bt((unsigned int) (p_q));
            for(int i = sz; i <= std::min(p_q - 1, n); i++) {
                if(i == 0) {
                    f[id][i] = 1;
                } else {
                    if(i % p == 0) {
                        f[id][i] = f[id][i - 1];
                    } else {
                        f[id][i] = bt.mul(f[id][i - 1], i);
                    }
                }
                inv_f[id][i] = atcoder::inv_mod(f[id][i], p_q);
            }
            id++;
        }
    }
    static long long pow_ll(long long x, long long n) {
        assert(0 <= n && 1 <= m);
        long long r = 1, y = x;
        while(n) {
            if(n & 1)
                r *= y;
            n >>= 1;
            if(n)
                y *= y;
        }
        return r;
    }
    static inline long long m = -1;
    static inline long long max_p_q = -1;
    static inline long long max_size = 0;
    static inline std::map<long long, int> factors{};
    static inline std::vector<std::vector<long long>> f{};
    static inline std::vector<std::vector<long long>> inv_f{};
};
const ll MOD = 1e9 + 7;
int main() {
    int tt, m;
    cin >> tt;
    using binom = binomial_coefficient_arbitrary_mod;
    binom::sed_mod(MOD);
    while(tt--) {
        ll n;
        cin >> n;
        cout << binom::C(2 * n, n + 1) << '\n';
    }
}
