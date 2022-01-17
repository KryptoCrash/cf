#include <bits/stdc++.h>
using namespace std;

using ll = int;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

struct DSU {
    vi par;
    vi sz;
    void init(ll n) {
        par.clear();
        sz.clear();
        for (ll i = 0; i < n; i++) {
            par.push_back(i);
            sz.push_back(1);
        }
    }
    ll get_rep(ll node) {
        if (par[node] == node) return node;
        return get_rep(par[node]);
    }
    bool check_con(ll a, ll b) {
        return get_rep(a) == get_rep(b);
    }
    void unite(ll a, ll b) {
        ll x = get_rep(a);
        ll y = get_rep(b);
        if (x == y) return;
        if (sz[x] < sz[y]) {
            par[x] = y;
            sz[y] += sz[x];
        } else {
            par[y] = x;
            sz[x] += sz[y];
        }
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<array<ll, 3>> ed(m);
    vb bad(m);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        ed[i] = {u, v, w};
    }

    DSU dsu;

    ll ans = 0;

    for (ll bit = 30; bit >= 0; bit--) {
        dsu.init(n);

        for (ll i = 0; i < m; i++) {
            if (bad[i]) continue;
            ll w = ed[i][2] & (1 << bit);

            if (w == 0) dsu.unite(ed[i][0], ed[i][1]);
        }

        if (dsu.sz[dsu.get_rep(0)] == n) {
            for (ll i = 0; i < m; i++) {
                ll w = ed[i][2] & (1 << bit);
                if (w != 0) bad[i] = true;
            }
        } else
            ans += (1 << bit);
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