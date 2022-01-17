#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const int INF = 1e9;

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vi> dp(n + 1, vi(2e3 + 1, INF));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2e3; j++) {
            if(dp[i][j] == INF) continue;

            ll l = j;
            ll r = dp[i][j];

            // move left
            ll newl = l - a[i];
            newl = max(newl, 0LL);
            dp[i + 1][newl] = min(dp[i + 1][newl], r + a[i]);

            // move right
            ll newr = r - a[i];
            newr = max(newr, 0LL);
            if (l + a[i] <= 2e3) dp[i + 1][l + a[i]] = min(dp[i + 1][l + a[i]], newr);
        }
    }

    ll best = INF;
    for (int i = 0; i <= 2e3; i++) {
        best = min(best, dp[n][i] + i);
    }

    cout << best << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}