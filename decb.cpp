#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;

const ll INF = 1e9;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<set<ll>> ed(n);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        ed[a].insert(b);
        ed[b].insert(a);
    }

    vb vis(n);

    vi comp(n);
    ll cur_comp = 0;
    function<void(ll)> dfs = [&](ll v) {
        if (vis[v]) return;

        comp[v] = cur_comp;
        vis[v] = true;

        for (ll ch : ed[v]) {
            dfs(ch);
        }
    };

    for (ll i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i);
        cur_comp++;
    }

    set<ll> set1;
    set<ll> setn;

    if (comp[0] == comp[n - 1]) {
        cout << 0 << endl;
        return;
    }

    for (ll i = 0; i < n; i++) {
        if (comp[0] == comp[i]) set1.insert(i);
        if (comp[n - 1] == comp[i]) setn.insert(i);
    }

    vi min1(n, INF);
    vi minn(n, INF);

    for (ll i = 0; i < n; i++) {
        auto it = set1.lower_bound(i);
        if (it == set1.end()) continue;
        ll val = *it - i;
        min1[comp[i]] = min(min1[comp[i]], val * val);
    }

    for (ll i = 0; i < n; i++) {
        auto it = set1.lower_bound(i);
        if (it == set1.begin()) continue;
        --it;
        ll val = *it - i;
        min1[comp[i]] = min(min1[comp[i]], val * val);
    }

    for (ll i = 0; i < n; i++) {
        auto it = setn.lower_bound(i);
        if (it == setn.end()) continue;
        ll val = *it - i;
        minn[comp[i]] = min(minn[comp[i]], val * val);
    }

    for (ll i = 0; i < n; i++) {
        auto it = setn.lower_bound(i);
        if (it == setn.begin()) continue;
        --it;
        ll val = *it - i;
        minn[comp[i]] = min(minn[comp[i]], val * val);
    }

    ll ans = INF;
    for (ll i = 0; i < n; i++) {
        ans = min(ans, minn[i] + min1[i]);
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