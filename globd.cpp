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

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b(n);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }

    vi psum(n + 1);

    for (ll i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + a[i] + b[i];
    }

    ll INF = 1e18;
    ll SUM = 100 * 100 + 8;

    vector<vector<ll>> dp(n + 1, vector<ll>(SUM, INF));
    vector<vector<array<ll, 3>>> path(n + 1, vector<array<ll, 3>>(SUM, {-1, -1, -1}));
    dp[0][0] = 0;

    for (ll i = 0; i < n; i++) {
        for (ll s = 0; s < SUM; s++) {
            if (dp[i][s] == INF) continue;

            // choose normal
            ll cst1 = dp[i][s] + s * a[i] + (psum[i] - s) * b[i];
            if (cst1 < dp[i + 1][s + a[i]]) {
                dp[i + 1][s + a[i]] = cst1;
                path[i + 1][s + a[i]] = {i, s, 0};
            }

            // swap them
            ll cst2 = dp[i][s] + s * b[i] + (psum[i] - s) * a[i];

            if (cst2 < dp[i + 1][s + b[i]]) {
                dp[i + 1][s + b[i]] = cst2;
                path[i + 1][s + b[i]] = {i, s, 1};
            }
        }
    }

    ll curmin = INF;
    pi cur = {-1, -1};
    for (ll s = 0; s < SUM; s++) {
        if (dp[n][s] == INF) continue;
        if (dp[n][s] < curmin) {
            curmin = dp[n][s];
            cur = {n, s};
        }
    }

    vi patha;
    vi pathb;

    while (cur.first != -1) {
        array<ll, 3> thing = path[cur.first][cur.second];
        cur = {thing[0], thing[1]};
        if (thing[0] == -1) break;
        if (thing[2] == 0) {
            patha.push_back(a[thing[0]]);
            pathb.push_back(b[thing[0]]);

        } else {
            patha.push_back(b[thing[0]]);
            pathb.push_back(a[thing[0]]);
        }
    }

    assert(patha.size() == n);
    assert(pathb.size() == n);

    ll finalans = 0;

    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            finalans += (patha[i] + patha[j]) * (patha[i] + patha[j]);
            finalans += (pathb[i] + pathb[j]) * (pathb[i] + pathb[j]);
        }
    }

    cout << finalans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) solve();

    return 0;
}