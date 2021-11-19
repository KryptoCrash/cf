#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;

void solve() {
    ll n, k;
    cin >> n >> k;

    vi a(n);
    ll x = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
    }

    vector<set<ll>> ed(n, set<ll>());

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;

        ed[u].insert(v);
        ed[v].insert(u);
    }

    if (x == 0) {
        cout << "YES" << endl;
        return;
    }

    // root tree and do weird xor dfs
    vi x_sum(n);
    ll found = 0;
    function<pair<ll, bool>(ll, ll)> dfs = [&](ll v, ll p) {
        ll xo = a[v];
        bool works = true;
        for (ll child : ed[v]) {
            if (child != p) {
                pi f = dfs(child, v);
                xo ^= f.first;
                if(f.second) works = false;
            }
        }
        x_sum[v] = xo;
        if (works && xo == x) found++;
        if (!works && xo == 0) found++;
        return make_pair(xo, xo == x || works == false);
    };

    dfs(0, -1);

    if (found >= 2 && k > 2) cout << "YES" << endl;                         
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) solve();

    return 0;
}