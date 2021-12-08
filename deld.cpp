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

    ll n, d;
    cin >> n >> d;

    DSU dsu;
    dsu.init(n);

    ll u = 0;
    for (ll i = 0; i < d; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;

        if(dsu.check_con(x, y)) {
            u++;
        } else {
            dsu.unite(x, y);
        }

        multiset<ll, greater<ll>> szs;

        for (ll j = 0; j < n; j++) {
            if (dsu.get_rep(j) == j) szs.insert(dsu.sz[j]);
        }

        ll k = u + 1;
        ll tot = 0;

        for(ll j : szs) {
            if (k == 0) break;
            tot += j;
            k--;
        }

        cout << tot - 1 << endl;
    }

    return 0;
}