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

    vi nxt(n);
    vi val(n);
    ll tot = 0;

    for (ll i = 0; i < n; i++) {
        ll a, u;
        cin >> a >> u;
        a--;
        nxt[i] = a;
        val[i] = u;
        tot += val[i];
    }

    vi vis(n);
    vi st(n);
    ll idx = -1;
    vi cyc(n, -1);
    function<void(ll)> dfs = [&](ll v) {
        vis[v] = true;
        st[v] = true;

        ll ch = nxt[v];
        
        if(st[ch]) {
            idx = ch;
        } else if(!vis[ch])
            dfs(ch);

        st[v] = false;

        if (idx != -1) cyc[v] = idx;
        if(idx == v) idx = -1;
    };

    for (ll i = 0; i < n; i++) {
        idx = -1;
        if (!vis[i]) dfs(i);
    }

    vi mn(n, 1e9 + 7);

    for (ll i = 0; i < n; i++) {
        if(cyc[i] != -1) {
            mn[cyc[i]] = min(mn[cyc[i]], val[i]);
        }
    }

    vi chose(n);

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        if(cyc[i] != -1 && !chose[cyc[i]]) {
            chose[cyc[i]] = true;
            ans += mn[cyc[i]];
        }
    }

    cout << (tot - ans) << endl;

    return 0;
}