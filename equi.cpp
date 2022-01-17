#include <bits/stdc++.h>

#include <atcoder/segtree>
using namespace atcoder;
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

ll mapping(ll x, ll y) {
    return min(x, y);
}

ll mapping2(ll x, ll y) {
    return max(x, y);
}

ll e() {
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        ll b;
        cin >> b;
        a[i] -= b;
    }

    vi psum(n + 1);

    for (ll i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + a[i];
    }

    segtree<ll, mapping, e> st(psum);
    segtree<ll, mapping2, e> st2(psum);
    
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;

        ll mn = st.prod(l, r) - psum[l - 1];
        ll mx = st2.prod(l, r) - psum[l - 1];

        ll sum = psum[r] - psum[l - 1];
        if (sum == 0 || mx > 0) cout << -1 << endl;
        else {
            cout << -mn << endl;
        }
    }

    return 0;
}