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

    ll ma = 0;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    ma += 8;
    ma *= 2;

    vi th(ma);
    for (ll i = 0; i < n; i++) {
        th[a[i]]++;
    }

    vi cnt(ma);

    for (ll x = 1; x < ma; x++) {
        for (ll m = 1; m * x < ma; m++) {
            cnt[x] += th[m * x];
        }
    }

    vi dp(ma);
    ll best = 0;
    for (ll x = 1; x < ma; x++) {
        for (ll m = 2; m * x < ma; m++) {
            dp[m * x] = max(dp[m * x], dp[x] + x * (cnt[x] - cnt[m * x]));
            best = max(best, dp[m * x] + cnt[m * x]);
        }
    }

    cout << best << endl;

    return 0;
}