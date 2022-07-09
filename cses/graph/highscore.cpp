#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;
set<pair<pi, ll>> edge;
vector<set<ll>> parent;
vi dist;
vector<bool> conn;

void dfs(ll node) {
    if (conn[node]) return;
    conn[node] = true;

    for (ll p : parent[node]) {
        dfs(p);
    }
}

int main() {
    cin >> n >> m;

    edge = set<pair<pi, ll>>();
    dist = vi(n, LLONG_MIN);
    parent = vector<set<ll>>(n);
    conn = vector<bool>(n, false);

    dist[0] = 0;

    for (ll i = 0; i < m; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        a--, b--;

        parent[b].insert(a);
        edge.insert({{a, b}, x});
    }

    dfs(n - 1);

    // bellman ford
    for (ll i = 0; i < n; i++) {
        for (pair<pi, ll> e : edge) {
            ll a = e.first.first;
            ll b = e.first.second;
            ll x = e.second;

            if (dist[a] != LLONG_MIN) dist[b] = max(dist[b], dist[a] + x);
        }
    }

    // find negative cycles

    for (pair<pi, ll> e : edge) {
        ll a = e.first.first;
        ll b = e.first.second;
        ll x = e.second;

        if (dist[a] != LLONG_MIN && dist[a] + x > dist[b] && conn[a]) {
            // cycle found
            cout << -1 << endl;

            return 0;
        }
    }

    cout << dist[n - 1] << endl;

    return 0;
}