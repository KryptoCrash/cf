#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

struct DSU {
    vi par;
    vi sz;
    void init(ll n) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll m;
    cin >> m;

    vector<set<int>> ed(n);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        ed[a].insert(b);
        ed[b].insert(a);
    }

    vector<set<int>> comps;

    for (int i = 0; i < n; i++) {

    }

        return 0;
}