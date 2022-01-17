#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<array<ll, 3>> p(n);
    map<ll, map<ll, ll>> mp1;
    map<ll, map<ll, ll>> mp2;
    for (ll i = 0; i < n; i++) {
        ll x, y, t;
        cin >> x >> y >> t;
        p[i][0] = x;
        p[i][1] = y;
        p[i][2] = t;
        mp1[x][y] = i;
        mp2[y][x] = i;
    }

    vb vis(n);
    ll cc = 0;
    vi comp(n);
    vi compmin(n, 1e9);

    function<void(ll)> dfs = [&](ll v) {
        if (vis[v]) return;
        vis[v] = true;
        comp[v] = cc;
        compmin[cc] = min(compmin[cc], p[v][2]);

        auto it = mp1[p[v][0]];
        auto it2 = it.find(p[v][1]);
        if (it2 != it.begin()) {
            it2--;
            if (p[v][1] - p[(*it2).second][1] <= k) {
                dfs((*it2).second);
            }
            it2++;
        }

        it2++;
        if (it2 != it.end() && p[(*it2).second][1] - p[v][1] <= k) {
            dfs((*it2).second);
        }

        it = mp2[p[v][1]];
        it2 = it.find(p[v][0]);
        if (it2 != it.begin()) {
            it2--;
            if (p[v][0] - p[(*it2).second][0] <= k) {
                dfs((*it2).second);
            }
            it2++;
        }
        it2++;
        if (it2 != it.end() && p[(*it2).second][0] - p[v][0] <= k) {
            dfs((*it2).second);
        }
    };

    for (ll i = 0; i < n; i++) {
        if (vis[i]) continue;

        dfs(i);
        cc++;
    }

    vi path;
    for (ll i : compmin) {
        if (cc == 0) break;
        cc--;
        path.push_back(i);
    }

    sort(path.begin(), path.end());

    ll ans = 0;
    for (ll i = 0; i < path.size(); i++) {
        ans = max(ans, min((ll)path.size() - 1 - i, path[i]));
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