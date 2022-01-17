#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

template <class T>
struct Seg {  // comb(ID,b) = b

    const T ID = 0;
    T comb(T a, T b) { return (a + b) % mod; }

    ll n;
    vector<T> seg;

    void init(ll _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }

    void pull(ll p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }

    void upd(ll p, T val) {  // set val at position p

        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(ll l, ll r) {  // sum on llerval [l, r]

        T ra = ID, rb = ID;

        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);

            if (r & 1) rb = comb(seg[--r], rb);
        }

        return comb(ra, rb);
    }
};

const ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    Seg<long long> st;
    Seg<long long> st2;
    st.init(1e9 + 8);
    st2.init(1e9 + 8);

    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        ll x = st.query(1, a[i]) % mod;
        ll y = st.query(1, min(a[i], a[i + 1])) % mod;

        ll c = a[i + 1];

        ll d = min(a[i + 1], a[i]);
        st2.upd(1, c, (c * x) % mod - y);
        st2.upd(c + 1, d, ((d - c) * x) % mod);

        st = st2;
        st2.init(1e9 + 8);
    }

    cout << st.query(1, a[n - 1]) % mod << endl;

    return 0;
}