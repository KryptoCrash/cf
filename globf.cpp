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
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        ed[u].insert(v);
        ed[v].insert(u);
    }

    vi cst(n);
    vi mx(n);

    function<void(ll, ll)> dfs2 = [&](ll v, ll p) {
        
    }

    function<void(ll, ll)> dfs = [&](ll v, ll p) {
        if (v == 0) {
            ll mxv = 0;
            ll tot = 0;
            ll mxi = -1;
            ll mxv2 = 0;
            ll mxi2 = -1;

            for (ll ch : ed[v]) {
                if (ch != p) {
                    dfs(ch, v);
                    if (mx[ch] > mxv) {
                        mxv = mx[ch];
                        mxi = ch;
                    }
                    tot += cst[ch];
                }
            }

            for (ll ch : ed[v]) {
                if (ch != p) {
                    if (mx[ch] > mxv2 && ch != mxi) {
                        mxv2 = mx[ch];
                        mxi2 = ch;
                    }
                }
            }

            if (a[v] > mxv) {
                tot += a[v] - mxv;
                mxv = a[v];
            }

            if (mxi2 == -1)
                tot += mxv;
            else if (a[v] > mxv2) {
                tot += a[v] - mxv2;
                mxv2 = a[v];
            }

            cst[v] = tot;
            mx[v] = mxv;
        } else {
            ll mxv = 0;
            ll tot = 0;

            for (ll ch : ed[v]) {
                if (ch != p) {
                    dfs(ch, v);
                    mxv = max(mxv, mx[ch]);
                    tot += cst[ch];
                }
            }

            if (a[v] > mxv) {
                tot += a[v] - mxv;
                mxv = a[v];
            }

            cst[v] = tot;
            mx[v] = mxv;
        }
    };

    dfs(0, -1);

    cout << cst[0] << endl;

    return 0;
}