#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
#include <sys/resource.h>
// DSU template by usacoguide

struct DSU {
    vi par;
    vi sz;
    vi lca;
    void init(ll n) {
        for (ll i = 0; i < n; i++) {
            par.push_back(i);
            sz.push_back(1);
            lca.push_back(i);
        }
    }
    ll get_lca(ll node) {
        return lca[node];
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
    ll n;
    cin >> n;

    vector<set<ll>> ed(n);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        ed[a].insert(b);
        ed[b].insert(a);
    }

    vector<set<ll>> f(n);
    for (ll i = 0; i < n; i++) {
        ll j;
        cin >> j;
        j--;

        f[j].insert(i);
    }

    // dfs to get par
    vector<set<ll>> adj(n);
    vector<ll> par(n);

    function<void(ll, ll)> dfs2 = [&](ll v, ll p) {
        par[v] = p;
        for (ll to : ed[v]) {
            if(to != p) {
                adj[v].insert(to);
                dfs2(to, v);
            }
        }
    };

    dfs2(0, -1);

    

    // lca (Template from BenQ)

    ll T = 1;
    vi st, en;
    vector<array<ll, 20>> up(n, array<ll, 20>{});

    function<void(ll, ll)> dfs = [&](ll v, ll p) {
        st[v] = T++;
        up[v][0] = p;

        for (ll i = 1; i < 20; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }

        for (ll x : adj[v])
            if (x != p) dfs(x, v);

        en[v] = T - 1;
    };

    function<bool(ll, ll)> anc = [&](ll a, ll b) {
        return st[a] <= st[b] && en[a] >= en[b];
    };

    function<ll(ll, ll)> LCA = [&](ll a, ll b) {
        if (anc(a, b)) return a;
        if (anc(b, a)) return b;

        for (ll i = 20 - 1; i >= 0; --i) {
            if (!anc(up[a][i], b))
                a = up[a][i];
        }
        return up[a][0];
    };

    st.resize(n);
    en.resize(n);

    dfs(0, 0);

    // take lca of similar nodes and store them in a dsu

    DSU dsu;

    dsu.init(n);

    vector<bool> used(n);

    for (ll i = 0; i < n; i++) {
        if (f[i].size() == 0) continue;
        ll c_lca = *f[i].begin();
        for (ll node : f[i]) {
            c_lca = LCA(c_lca, node);
        }

        set<ll> added;

        for (ll node : f[i]) {
            // traverse up until reach lca
            ll curr = node;
            while (curr != c_lca && LCA(c_lca, curr) == c_lca) {
                curr = par[curr];
                cout << curr << endl;
                used[curr] = true;
                added.insert(curr);
                curr = dsu.get_lca(dsu.get_rep(curr));
                cout << curr << endl;
            }
        }

        if (added.size() == 0) continue;
        ll last_added = *added.begin();
        for (ll node : added) {
            dsu.unite(last_added, node);
            last_added = node;
        }
        dsu.lca[dsu.get_rep(last_added)] = c_lca;
    }

    ll ans = n - 1;
    for (bool edge : used) {
        ans -= edge;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const rlim_t kStackSize = 1024 * 1024 * 1024;
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
        }
    }

    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}