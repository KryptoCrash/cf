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

    const int mod = 998244353;

    ll n, x;
    cin >> n >> x;

    vector<vi> power(x + 1, vi(n + 1));
    vector<vi> c(n + 1, vi(n + 1));

    for (int i = 0; i <= x; i += 1)
        for (int j = 0; j <= n; j += 1)
            power[i][j] = j ? power[i][j - 1] * i % mod : 1;
    for (int i = 0; i <= n; i += 1)
        for (int j = 0; j <= i; j += 1)
            c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % mod : 1;

    vector<vi> dp(n + 1, vi(x + 1));

    for (int i = 0; i < x + 1; i++) {
        dp[1][i] = x - i + 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = x; j >= 1; j--) {
            for (int k = 0; k <= i; k++) {
                if (j + i - 1 < x + 1) dp[i][j] += ((dp[k][j + i - 1] * c[i][i - k]) % mod * power[i - 1][i - k]) % mod;
                dp[i][j] %= mod;
            }
        }
    }

    cout << (power[x][n] + mod - dp[n][1]) % mod << endl;

    return 0;
}