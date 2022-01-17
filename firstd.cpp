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

    vi b(n);
    vb vis(2 * n + 1);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        vis[b[i]] = true;
    }

    vi c(n);
    ll lst = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        if (!vis[i]) c[lst++] = i;
    }

    vector<array<ll, 2>> pos(n + 1);
    for(ll j = 0; j < 2; j++) {
        vi num(n);
        ll lsti = n - 1;
        ll summ = 0;
        for (ll i = 2 * n; i > 0; i--) {
            if (!vis[i]) summ++;
            else num[lsti--] = summ;
        }

        vi maxk(n);
        for (ll i = 0; i < n; i++) {
            maxk[i] = num[i] + i;
            //cout << num[i] << " " << maxk[i] << endl;
        }

        pos[0][j] = true;
        ll sweepmin = 1e9;
        for (ll i = 0; i < n; i++) {
            ll k = i + 1;
            sweepmin = min(sweepmin, maxk[i]);
            if (k > sweepmin) break;
            pos[k][j] = true;
        }

        vis.clear();
        vis.resize(2 * n + 1);
        for (ll i = 0; i < n; i++) {
            b[i] = 2*n - b[i] + 1;
            vis[b[i]] = true;
        }
        c.clear();
        c.resize(n);

        lst = 0;
        for (ll i = 1; i <= 2 * n; i++) {
            if (!vis[i]) c[lst++] = i;
        }
        //cout << endl;
    }

    /*

    vi num2(n);
    ll lsti2 = 0;
    ll summ2 = 0;
    for (ll i = 1; i <= 2 * n; i++) {
        if (!vis[i]) summ2++;
        else num2[lsti2++] = summ2;
    }

    vi maxk2(n);
    for (ll i = 0; i < n; i++) {
        maxk2[i] = num2[i] + (n - i);
    }

    vi pos2(n + 1);
    pos2[n] = true;
    ll sweepmin2 = 1e9;
    for (ll i = n - 1; i >= 0; i--) {
        ll k = i - 1;
        sweepmin2 = min(sweepmin2, num2[i]);
        if (k > sweepmin2) break;
        pos2[k] = true;
    }
    */

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        //cout << pos[i][0] << " " << pos[n - i][1] << endl;
        if (pos[i][0] && pos[n - i][1]) ans++;
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