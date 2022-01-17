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
    ll tot;
    void init(ll n) {
        for (ll i = 0; i < n; i++) {
            par.push_back(i);
            sz.push_back(1);
            tot = 0;
        }
    }
    ll get_rep(ll node) {
        if (par[node] == node) return node;
        return get_rep(par[node]);
    }
    ll get_sz(ll node) {
        return sz[get_rep(node)];
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
            tot -= sz[x] / 2;
            tot -= sz[y] / 2;
            sz[y] += sz[x];
            tot += sz[y] / 2;
        } else {
            par[y] = x;
            tot -= sz[x] / 2;
            tot -= sz[y] / 2;
            sz[x] += sz[y];
            tot += sz[x] / 2;
        }
    }
};

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end()); 

    priority_queue<pi> q;
    DSU dsu;
    dsu.init(n);

    ll best = n;
    for (int i = n - 1; i >= 0; i--) {
        ll ans = i;
        
        while (!q.empty()) {
            if (q.top().first <= a[i]) break;
            pi top = q.top();

            q.pop();

            ll v = top.second;
            dsu.unite(v, v + 1);
        }

        if(i > 0) q.push({2 * a[i - 1] - a[i], i-1});

        ans += dsu.tot;
        best = min(best, ans);
    }

    cout << best << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}