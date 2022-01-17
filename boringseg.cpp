#include <bits/stdc++.h>
#include <atcoder/lazysegtree>

using namespace atcoder;
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

ll min_v(ll a, ll b) {
    return min(a, b);
}

ll e() {
    return 0;
}

ll mapping(ll f, ll x) {
    return f + x;
}

ll composition(ll f, ll g) {
    return f + g;
}

ll id() {
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<array<ll, 3>> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][0];
    }

    sort(a.begin(), a.end());

    ll r = 0;
    ll mn = 1e9;

    lazy_segtree<ll, min_v, e, ll, mapping, composition, id> st;

    function<bool(void)> conn = [&]() {
        // get min on segtree and check if its > 0
        return st.prod(0, m) > 0;
    };

    function<void(ll, ll)> add = [&](ll l, ll r) {
        // add on [l, r]
        st.apply(l, r, 1);
    };

    function<void(ll, ll)> rem = [&](ll l, ll r) {
        // sub on [l, r]
        st.apply(l, r, -1);
    };

    for (ll l = 0; l < n; l++) {
        while(!conn() && r < n) {
            add(a[r][1], a[r][2]);

            r++;
        }

        if (conn()) mn = min(mn, a[r][0] - a[l][0]);
        rem(a[l][1], a[l][2]);
        l++;
    }

    return 0;
}