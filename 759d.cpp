#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll MX = 5e5 + 8;

template <class T>
struct Seg {  // comb(ID,b) = b

    const T ID = 0;
    T comb(T a, T b) { return a + b; }

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

void solve() {
    ll n;
    cin >> n;

    Seg<long long> st;
    st.init(n + 8);

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll inv = 0;
    for (ll i = 0; i < n; i++) {
        inv += st.query(a[i] + 1, n + 5);
        st.upd(a[i], st.query(a[i], a[i]) + 1);
    }

    sort(a.begin(), a.end());
    if(adjacent_find(a.begin(), a.end()) != a.end()) {
        cout << "YES" << endl;
        return;
    }

    cout << (inv % 2 ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}