#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll INF = 1e9;

/*
dfs to get dist to start and dist to nearest end

recurse on subtrees
check if you can get to current root node (dist to start < dist to nearest end)
if you can, recurse on subtrees
*/

void solve() {
    ll n, k;

    cin >> n >> k;

    vi dist_to_start(n);
    vi dist_to_end(n);
    vector<set<ll>> ed(n);
    vb cc(n);
    for (ll i = 0; i < k; i++) {
        ll ki;
        cin >> ki;
        ki--;
        cc[ki] = true;
    }

    for (ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;

        ed[x].insert(y);
        ed[y].insert(x);
    }

    function<void(ll, ll)> removePar = [&](ll node, ll par) {
        if (par != -1) ed[node].erase(par);
        for (ll child : ed[node]) {
            removePar(child, node);
        }
    };

    function<ll(ll, ll)> dfs = [&](ll node, ll depth) {
        dist_to_start[node] = depth;
        ll near_end = INF;
        for (ll child : ed[node]) {
            near_end = min(near_end, dfs(child, depth + 1));
        }

        dist_to_end[node] = cc[node] ? 0 : near_end + 1;

        return dist_to_end[node];
    };

    ll ans = 0;

    bool works = false;
    function<void(ll)> dfs2 = [&](ll node) {
        if (dist_to_start[node] >= dist_to_end[node]) {
            ans++;
            return;
        };
        if (ed[node].size() == 0) works = true;
        for (ll child : ed[node]) {
            dfs2(child);
        }
    };

    removePar(0, -1);

    dfs(0, 0);

    dfs2(0);

    cout << (works ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}