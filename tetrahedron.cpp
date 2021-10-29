#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxn = 1e7;
const ll mod = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    ll* dp = new ll[maxn * 2];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (ll i = 0; i < n; i++) {
        dp[(i + 1) * 2 + 0] = dp[i * 2 + 1] * 3;
        dp[(i + 1) * 2 + 1] = dp[i * 2 + 0] + dp[i * 2 + 1] * 2;
        dp[(i + 1) * 2 + 0] %= mod;
        dp[(i + 1) * 2 + 1] %= mod;
    }

    cout << dp[n * 2] << endl;

    return 0;
}
