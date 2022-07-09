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
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b = a;
    reverse(b.begin(), b.end());

    vector<vector<vi>> dp(n+1, vector<vi>(n+1, vi(n+1)));

    ll mx = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (a[i - 1] == b[j - 1] && a[i-1] == k) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + (i - 1 == n - j ? 1 : 2));
                    //cout << "WHAT " << i << " " << j << " " << (i - 1 == n - j) << " " << dp[i][j][k] << endl;
                    if (i - 1 == n - j) mx = max(mx, dp[i][j][k]);
                }
                dp[i][j][k] = max(dp[i][j][k], max(dp[i][j][k-1], max(dp[i-1][j][k], dp[i][j-1][k])));

                //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }

    cout << (mx >= 3 ? mx : 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}