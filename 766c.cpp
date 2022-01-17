#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n;
    cin >> n;

    vector<set<pi>> ed(n);
    vi deg(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
        ed[u].insert({v, i});
        ed[v].insert({u, i});
    }

    bool works = true;
    ll lst = 0;
    for (ll i = 0; i < n; i++) {
        if (deg[i] > 2) works = false;
        if (deg[i] == 1) lst = i;
    }

    if(!works) {
        cout << -1 << endl;
        return;
    }

    vb vis(n);
    vi ans(n - 1);

    function<void(ll, ll,ll)> dfs = [&](ll v, ll l, ll par) {
        if(vis[v]) return;
        vis[v] = true;
        
        for(auto ch : ed[v]) {
            ll val = ch.first;
            ll idx = ch.second;
            if (val == par) continue;
            ans[idx] = l;
            dfs(val, (l == 3 ? 2 : 3), v);
        }
    };

    dfs(lst, 2, -1);

    for(ll i : ans) {
        cout << i << " ";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}