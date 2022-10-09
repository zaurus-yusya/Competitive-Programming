#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 1e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}


namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

using S = long long;
ll op(ll a, ll b) {
    return a + b;
}

ll e() {
    return 0;
}

//宣言
//segtree<S, op, e> seg(n); //e()で初期化
//segtree<S, op, e> seg(vec); //vecの値で初期化
//seg.set(i, x); //i番目の値をxに更新
//seg.get(i); //i番目の要素を取得
//seg.prod(l, r); //[l, r)の区間のopを計算
//seg.all_prod(); //[0, n)の区間のopを計算
//seg.max_right<f>(l); //未履修
//seg.min_left<f>(r); //未履修
//単位元 e()
//min: INF, max: -INF, 和: 0, 積: 1, xor: 0, gcd: 0, lcm: 1

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, m; cin >> n >> m; // m回更新 sum n + m 7000000
        vector<long long> a(n);
        ll sum = 0;
        
        segtree<S, op, e> seg(n);
        segtree<S, op, e> seg1(n);
        segtree<S, op, e> seg2(n);
        segtree<S, op, e> seg3(n);

        for(long long i = 0; i < n; i ++){
            cin >> a[i];
            sum += a[i];

            seg.set(i, a[i]);
            if(a[i] == 1){
                seg1.set(i, 1);
            }
            if(a[i] == 2){
                seg2.set(i, 1);
            }
            if(a[i] == 3){
                seg3.set(i, 1);
            }
        }

        // cout << seg.all_prod() << endl;
        // cout << seg1.all_prod() << endl;
        // cout << seg2.all_prod() << endl;
        // cout << seg3.all_prod() << endl;

        ll ans = 0;
        rep(i, m){
            // cerr << "q = " << i+1 << endl;
            ll x, y, z; cin >> x >> y >> z; x--;
            // cerr << x << " " << y << " " << z << endl;

            ll bef = seg.get(x);
            ll aft = y;
            seg.set(x, y);

            if(bef == 1){
                seg1.set(x, 0);
            }else if(bef == 2){
                seg2.set(x, 0);
            }else if(bef == 3){
                seg3.set(x, 0);
            }

            if(aft == 1){
                seg1.set(x, 1);
            }else if(aft == 2){
                seg2.set(x, 1);
            }else if(aft == 3){
                seg3.set(x, 1);
            }

            // cout << seg.all_prod() << endl;
            // cout << seg.prod(0, z) << " " << seg.prod(z, n) << endl;
            // cout << seg1.prod(0, z) << " " << seg1.prod(z, n) << endl;
            // cout << seg2.prod(0, z) << " " << seg2.prod(z, n) << endl;
            // cout << seg3.prod(0, z) << " " << seg3.prod(z, n) << endl;
            // cerr << "---" << endl;

            ll left = seg.prod(0, z);
            ll right = seg.prod(z, n);
            if(left == right){
                // q = 0
                ans += 0;
                // cerr << "ans = " << ans << endl;
                continue;
            }else{
                if(abs(left - right) % 2 == 1){
                    // 無理
                    ans -= 1;
                    // cerr << "ans = " << ans << endl;
                }else{
                    map<ll, ll> L;
                    map<ll, ll> R;
                    L[1] = seg1.prod(0, z);
                    L[2] = seg2.prod(0, z);
                    L[3] = seg3.prod(0, z);
                    R[1] = seg1.prod(z, n);
                    R[2] = seg2.prod(z, n);
                    R[3] = seg3.prod(z, n);

                    ll sa = abs(left - right);
                    // cerr << "sa = " << sa << endl;
                    ll tmp = 0;
                    if(left > right){
                        // 左から右へ
                        // 3 <-> 1
                        ll four = sa / 4;

                        // 差を4縮める移動
                        if(L[3] >= four && R[1] >= four){
                            L[3] -= four; R[3] += four; 
                            R[1] -= four; L[1] += four;
                            tmp += four;
                            // ans += four;

                            sa -= 4 * four;
                        }else{
                            // min回移動
                            ll x = min(L[3], R[1]);
                            L[3] -= x; R[3] += x; 
                            R[1] -= x; L[1] += x;
                            tmp += x;
                            // ans += x;

                            sa -= 4 * x;
                        }

                        // 差を2縮める移動
                        ll two = sa / 2;
                        // 2 <-> 1
                        if(L[2] >= two && R[1] >= two){
                            L[2] -= two; R[2] += two;
                            R[1] -= two; L[1] += two;
                            tmp += two;
                            // ans += two;

                            sa -= 2 * two;
                        }else{
                            // min回移動
                            ll x = min(L[2], R[1]);
                            L[2] -= x; R[2] += x;
                            R[1] -= x; L[1] += x;
                            tmp += x;
                            // ans += x;

                            sa -= 2 * x;
                        }

                        // 3 <->2
                        two = sa / 2;
                        if(L[3] >= two && R[2] >= two){
                            L[3] -= two; R[3] += two;
                            R[2] -= two; L[2] += two;
                            tmp += two;
                            // ans += two;

                            sa -= 2 * two;
                        }else{
                            // min回移動
                            ll x = min(L[3], R[2]);
                            L[3] -= x; R[3] += x;
                            R[2] -= x; L[2] += x;
                            tmp += x;
                            // ans += x;

                            sa -= 2 * x;
                        }

                    }else{
                        // 右から左へ

                        ll four = sa / 4;

                        // 差を4縮める移動
                        if(R[3] >= four && L[1] >= four){
                            R[3] -= four; L[3] += four;
                            L[1] -= four; R[1] += four;
                            tmp += four;
                            // ans += four;

                            sa -= 4 * four;
                        }else{
                            // min回移動
                            ll x = min(R[3], L[1]);
                            R[3] -= x; L[3] += x;
                            L[1] -= x; R[1] += x;
                            tmp += x;
                            // ans += x;

                            sa -= 4 * x;
                        }

                        // 差を2縮める移動
                        ll two = sa / 2;
                        // 2 <-> 1
                        if(R[2] >= two && L[1] >= two){
                            R[2] -= two; L[2] += two;
                            L[1] -= two; R[1] += two;
                            tmp += two;
                            // ans += two;

                            sa -= 2 * two;
                        }else{
                            // min回移動
                            ll x = min(R[2], L[1]);
                            R[2] -= x; L[2] += x;
                            L[1] -= x; R[1] += x;
                            tmp += x;
                            // ans += x;

                            sa -= 2 * x;
                        }

                        // 3 <->2
                        two = sa / 2;
                        if(R[3] >= two && L[2] >= two){
                            R[3] -= two; L[3] += two;
                            L[2] -= two; R[2] += two;
                            tmp += two;
                            // ans += two;

                            sa -= 2 * two;
                        }else{
                            // min回移動
                            ll x = min(R[3], L[2]);
                            tmp += x;
                            R[3] -= x; L[3] += x;
                            L[2] -= x; R[2] += x;
                            // ans += x;

                            sa -= 2 * x;
                        }
                    }

                    if(sa > 0){
                        ans -= 1;
                    }else{
                        ans += tmp;
                    }

                }
            }
            // cerr << "ans = " << ans << endl;
            // [0, z[i]) 区間が半分
        }

        cout << "Case #" << T+1 << ": " << ans << '\n';

    }

}