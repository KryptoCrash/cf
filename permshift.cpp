#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

void solve() {
    ll n, m;
    cin >> n >> m;

    vi p(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vi cnt(n);

    for (ll i = 0; i < n; i++) {
        ll nw = (i - p[i]) % n;
        if (nw < 0) nw += n;
        cnt[nw]++;
    }

    ll cc = 0;
    ll k = 0;
    vi vis(n);
    function<void(ll)> dfs = [&](ll i) {
        if (vis[i]) return;
        vis[i] = true;

        ll e = (p[i] + k) % n;
        if (e < 0) e += n;
        dfs(e);
    };

    vi path;
    for (; k < n; k++) {
        //cout << cnt[k] << endl;
        if (cnt[k] >= n / 3) {
            vis.clear();
            vis.resize(n);
            cc = 0;
            for (ll i = 0; i < n; i++) {
                if (!vis[i]) cc++, dfs(i);
            }
            //cout << k << " " << cc << endl;
            if (n - cc <= m) path.push_back(k);
        }
    }

    cout << path.size() << " ";
    for (ll i : path) cout << i << " ";
    cout << endl;
}

int main() {
    ll t;
    cin >> t;

    while (t--) solve();

    return 0;
}