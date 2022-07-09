#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<set<ll>> ed(n);

    vi b(n);
    vb chose(n);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == -1) {
            continue;
        }
        b[i]--;

        ed[b[i]].insert(i);
    }

    vb vis(n);
    vi res(n);

    ll ans = 0;

    vi path;
    vi path2;

    function<ll(ll)> dfs = [&](ll v) {
        if (vis[v]) return res[v];
        vis[v] = true;
        ll sum = a[v];
        for (ll ch : ed[v]) {
            sum += max(0LL, dfs(ch));
        }

        res[v] = sum;

        if (res[v] >= 0)
            path.push_back(v);
        else
            path2.push_back(v);

        ans += res[v];
        return sum;
    };

    for (ll i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }

    cout << ans << endl;

    for (ll i : path) cout << i + 1 << " ";
    reverse(path2.begin(), path2.end());
    for (ll i : path2) cout << i + 1 << " ";

    cout << endl;

    return 0;
}