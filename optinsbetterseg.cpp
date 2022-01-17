/*
TODO: Fix case where the best place to put something is before all values in ai

(might work to change how the psum and blocks work)
*/

#include <bits/stdc++.h>

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

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

}  // namespace atcoder

#include <cassert>
#include <iostream>
#include <vector>
namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;

using ll = int;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

pi mn(pi a, pi b) {
    if (a.first == b.first) return a.second > b.second ? a : b;
    return a.first < b.first ? a : b;
}

pi e() {
    return {1e9, -1};
}

pi mapping(ll d, pi x) {
    return {x.first + d, x.second};
}

ll composition(ll f, ll g) {
    return f + g;
}

ll id() {
    return 0;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    priority_queue<array<ll, 3>> ev;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ev.push({-a[i], i, 1});
    }

    vi b(m);
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    vi swap(n, 1);

    vi path(m);

    vpi psum(n + 1);

    for (ll i = 0; i <= n; i++) {
        psum[i] = {i, i};
    }

    lazy_segtree<pi, mn, e, ll, mapping, composition, id> seg(psum);

    for (ll c = 0; c < m; c++) {
        while (!ev.empty()) {
            array<ll, 3> top = ev.top();
            ll v = -top[0];
            ll i = top[1];
            ll tp = top[2];
            if (v > b[c]) break;
            ev.pop();
            ll dif;
            if (v == b[c] && tp == 1) dif = -swap[i], swap[i] = 0, ev.push({-(v + 1), i, 0});
            if (v < b[c] || (v == b[c] && tp == 0)) dif = -1 - swap[i], swap[i] = -1;
            seg.apply(i + 1, n + 1, dif);
        }

        path[c] = seg.all_prod().second;
    }

    // construct optimal array
    vpi opt;

    for (ll i = 0; i < n; i++) {
        opt.push_back({i, -1});
    }

    for (ll i = 0; i < m; i++) {
        opt.push_back({path[i]-1, i});
    }

    sort(opt.begin(), opt.end());

    vpi actual_opt(opt.size());
    for (ll i = 0; i < opt.size(); i++) {
        pi v = opt[i];
        actual_opt[i] = {v.second == -1 ? a[v.first] : b[v.second], i};
    }

    sort(actual_opt.begin(), actual_opt.end());

    map<ll, ll> coord;

    for(ll i = 0; i < opt.size(); i++) {
        ll v = actual_opt[i].first;

        coord[v] = i;
    }

    sort(actual_opt.begin(), actual_opt.end(), [](pi x, pi y) { return x.second < y.second; });

    // calc inversions on optimal array
    FenwickTree ft(opt.size() + 8);

    long long ans = 0;
    for (pi i : actual_opt) {
        ll v = coord[i.first];
        // find all things > v
        ans += ft.sum(v + 1, opt.size()+2);
        // add v to the thing
        ft.add(v, 1);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}

