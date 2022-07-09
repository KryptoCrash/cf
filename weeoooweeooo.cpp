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

    vpi a(n);
    ll mx;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        mx = max(mx, a[i].first);
    }

    sort(a.begin(), a.end());

    vector<vector<ll>> dp(n+1, vector<ll>(mx+1));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int t = 0; t <= mx; t++) {
            dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
            if (a[i].first >= t + a[i].second) dp[i + 1][t + a[i].second] = max(dp[i + 1][t + a[i].second], dp[i][t] + 1);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;

    return 0;
}