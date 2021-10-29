#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 5000 + 8;
const int mod = 1e9 + 7;

int dp[maxn][maxn];

int uses[maxn];

int main(int argc, char const *argv[]) {
    int n, k, q;
    cin >> n >> k >> q;

    int a[maxn];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, 0, sizeof(dp));
    memset(uses, 0, sizeof(uses));
    for (int i = 0; i < n; i++) {
        uses[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int u = 0; u <= k; u++) {
            // move left
            if (i > 0) {
                dp[i - 1][u + 1] += dp[i][u] + a[i];
                dp[i - 1][u + 1] %= mod;

                uses[i - 1]++;
            }
            // move right
            if (i < n - 1) {
                dp[i + 1][u + 1] += dp[i][u] + a[i];
                dp[i + 1][u + 1] %= mod;

                uses[i + 1]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i][k];
    }

    ans *= 2;

    for (int i = 0; i < n; i++) {
        cout << uses[i] << endl;
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        int temp = a[x];
        a[x] = y;
        ans += (a[x] - temp) * uses[x];
        cout << ans << endl;
    }

    return 0;
}
